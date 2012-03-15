#include <stdio.h>

#define LEN 1024

#define PR(var, fmt) \
  printf("printf: %c" #var "(%%" #fmt ")=%" #fmt "%c\n", ch, var, ch)

#define SPR(var, fmt) \
  snprintf(buf, LEN, "snprintf: %c" #var "(%%" #fmt ")=%" #fmt "%c\n", ch, var, ch); \
  printf("%s", buf)

int main()
{
  float fx = 10.0;
  double dx = 10.0;
  long double ldx = 10.0;
  char ch = '*';

  PR(fx, f);
  PR(fx, lf);
  PR(fx, Lf);
  PR(dx, f);
  PR(dx, lf);
  PR(dx, Lf);
  PR(ldx, f);
  PR(ldx, lf);
  PR(ldx, Lf);

  char buf[LEN];

  SPR(fx, f);
  SPR(fx, lf);
  SPR(fx, Lf);
  SPR(dx, f);
  SPR(dx, lf);
  SPR(dx, Lf);
  SPR(ldx, f);
  SPR(ldx, lf);
  SPR(ldx, Lf);
}
