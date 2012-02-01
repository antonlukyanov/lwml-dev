/*
 * for gcc.EXE (GCC) 4.6.2
 * the output of this program is:
 * 
 * 10.000000 10.000000 10 10
 * 10.000000 0.000000 5.31665e-315 3.9226e-4942
 */

#include <stdio.h>

#define LEN 1024

int main()
{
  double x = 10.0;
  printf("%f %lf %g %lg\n", x, x, x, x);

  char buf[LEN];
  snprintf(buf, LEN, "%f %lf %g %lg\n", x, x, x, x);
  printf("%s", buf);
}
