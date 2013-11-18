#include "stdio.h"
#include "math.h"

#define N 10000

int main(){
  float x4;
  int j;

  double x[N];
  for( j = 0; j < N; j++ )
    x[j] = 0.1;

  x4 = 0.0;
  for( j = 0; j < N; j++ )
    x4 += x[j];

  // алгоритм суммирования Кахана
  double s = 0.0;
  double c = 0.0;
  for( j = 0; j < N; j++ ){
    double y = x[j] - c;
    double t = s + y;
    c = (t - s) - y;
    s = t;
  }

  printf("%f - %d*(0.1) = %.25g\n", N*0.1, N, N*0.1-x4);
  printf("%f - %d*(0.1) = %.25g\n", N*0.1, N, N*0.1-s);
}
