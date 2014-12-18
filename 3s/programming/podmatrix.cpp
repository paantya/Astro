#include <iostream>
int main()
{
  omp_lock_t lockM,lockT;
  omp_init_lock(&lockT);
  omp_init_lock(&lockM);
  int x0,y0,x1,y1;
  #pragma omp parallel for
  for (int i = 0; i < 2; ++i)
  {
    std::cout << "Hello World!" << i << std::endl;
  }
  
  if (t>M){
    omp_set_lock(&lockM);
    if (t>M){
    //
    }
    omp_unset_lock(&lockM);
  }
  if (t<=0){
    omp_set_lock(&lockT);
    //
    omp_unset_lock(&lockT);
  }
  
  omp_destroy_lock(&lockM);
  omp_destroy_lock(&lockT);
  
  return 0;
}
