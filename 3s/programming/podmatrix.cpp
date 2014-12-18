#include <iostream>
#include <omp.h> 
using namespace std;

int main() {
  omp_lock_t lockM;
  omp_init_lock(&lockM);
  
  int n,m;
  int a[1000][1000]; 
  int x0,y0,x1,y1;
  double M;
  
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  
  #pragma omp parallel for
  for (int i = 0; i < n; ++i) {
    int t = 0;
    for (int j = 0 ; j < m; ++j) {
      for (int k = j; k < m; ++k) {
        do {
          t += a[i][k];
        } while ((++k < m) && (t > 0));
        int w = 0;
        for (int l = j; j < k; ++l) {
          for (int u = i; u < n; ++u) {
            w +=a[u][l];
            if (w > M) {
              omp_set_lock(&lockM);
              if (w > M){
                M = w;
                y0 = i;
                x0 = j;
                y1 = u;
                x1 = l;
                //
              }
              omp_unset_lock(&lockM);
            }                    
          }
          if (w <= 0) break;
        }
        t = 0;
        --k;
      }
      t = 0;
    }
  }
  
  cout << x0 <<", "<< y0 << endl << x1 <<", "<< y1 << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cout << a[i][j];
    cout << endl;
  } 
  
  omp_destroy_lock(&lockM); 
  return 0;
}
