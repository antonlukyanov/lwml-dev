#include "stdio.h"

int main( int argc, char *argv[] ){
  int j;

  double cf[] = { 0.299, 0.587, 0.114 };

  double x[3], y = 255.0;
  for( j = 0; j < 3; j++ )
    x[j] = 255 / y;

  double sum = 0.0;
  for( j = 0; j < 3; j++ )
    sum += cf[j] * x[j];

  printf("%e", sum - 1.0);
}
