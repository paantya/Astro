#include <iostream>
#include <omp.h> 
#include <limits>
using namespace std;

long lmin = numeric_limits<long>::min();
int n,m;

void max_podmatrix(int ** a, int &x0, int &y0, int &x1, int &y1) {
  long M = lmin;
  #pragma omp parallel for shared(M,x0,y0,x1,y1)
  for (size_t i = 0; i < n; ++i) {
    long t;
    for (size_t j = 0 ; j < m; ++j) {
      for (size_t k = j; k < m; ++k) {
        t = lmin;
        do {
          t += a[i][k];
          ++k;
        } while ((k < m) && (t > 0));        
        long w;        
        for (size_t q = j; q < k; ++q) {
          w = 0;
          for (size_t u = i; u < n; ++u) {            
            for (size_t l = j; l <=q; ++l) 
              w +=a[u][l];                   
            if (w > M) {
                #pragma omp critical
                if (w > M){
                  M = w;
                  y0 = i;
                  x0 = j;
                  y1 = u;
                  x1 = q;
                  //cout << "chang " << M << ':' << x0 << "." << y0 << ' ' \
                    << x1 << '.' << y1 << endl;
                }
              } 
            if (w <= 0) break;
          }
        }
        --k;
      }
    }
  }
}

int main() {
  int x0=-1,y0=-1,x1=-1,y1=-1;
  cin >> n >> m;
  int ** a = new int *[n];
  a[0] = new int[n * m];
  for ( size_t i = 1; i != n; ++i)
    a[i] = a[i - 1] + m;
  
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; ++j)
      cin >> a[i][j];
  
  max_podmatrix(a, x0, y0, x1, y1);
  
  cout << "y(n), x(m):\nbegin: " << y0 << ", " << x0 << "\nend:   " << y1 \
    << ", " << x1 << "\nMatrix:\n";
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j)
      cout << a[i][j] << ' ';
    cout << endl;
  } 
  
  return 0;
}
