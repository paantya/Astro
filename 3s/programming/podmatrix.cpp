#include <iostream>
#include <omp.h> 
using namespace std;
#include <limits>


int main() {
  omp_lock_t lockM;
  omp_init_lock(&lockM);
  long lmin = numeric_limits<long>::min();
  
  int n,m;
  int x0=-1,y0=-1,x1=-1,y1=-1;
  long M = lmin;
  cin >> n >> m;
  int a[n][m]; 
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  
  #pragma omp parallel for
  for (int i = 0; i < n; ++i) {
    long t;
    for (int j = 0 ; j < m; ++j) {
      for (int k = j; k < m; ++k) {
        t = lmin;
        do {
          t += a[i][k];
          ++k;
        } while ((k < m) && (t > 0));        
        int w = 0;        
        for (int q = j; q < k; ++q) {
          for (int u = i; u < n; ++u) {            
            for (int l = j; l <=q; ++l) 
              w +=a[u][l];                   
            if (w > M) {
                omp_set_lock(&lockM);
                if (w > M){
                  M = w;
                  y0 = i;
                  x0 = j;
                  y1 = u;
                  x1 = q;
                  //cout << "chang " << M << ':' << x0 <<"."<< y0 << ' ' << x1 << '.' << y1 << endl;
                }
                omp_unset_lock(&lockM);
              } 
            if (w <= 0) { w = 0; break; }
          }
          w = 0;
        }
        --k;
      }
    }
  }
  
  cout << "y(n), x(m):\nbegin: " << y0 <<", "<< x0 << "\nend:   " << y1 <<", "<< x1 << "\nMatrix:\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cout << a[i][j] << ' ';
    cout << endl;
  } 
  
  omp_destroy_lock(&lockM); 
  return 0;
}
