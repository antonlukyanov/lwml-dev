#include "mdefs.h"

using namespace lwml;

int main(){
  printf("floor(%lf)=%lf\n", 2.3, floor(2.3));
  printf("floor(%lf)=%lf\n", 2.5, floor(2.5));
  printf("floor(%lf)=%lf\n", 2.8, floor(2.8));
  printf("floor(%lf)=%lf\n", -2.3, floor(-2.3));
  printf("floor(%lf)=%lf\n", -2.5, floor(-2.5));
  printf("floor(%lf)=%lf\n", -2.8, floor(-2.8));

  printf("ceil(%lf)=%lf\n", 2.3, ceil(2.3));
  printf("ceil(%lf)=%lf\n", 2.5, ceil(2.5));
  printf("ceil(%lf)=%lf\n", 2.8, ceil(2.8));
  printf("ceil(%lf)=%lf\n", -2.3, ceil(-2.3));
  printf("ceil(%lf)=%lf\n", -2.5, ceil(-2.5));
  printf("ceil(%lf)=%lf\n", -2.8, ceil(-2.8));

  printf("trunc(%lf)=%lf\n", 2.3, trunc(2.3));
  printf("trunc(%lf)=%lf\n", 2.5, trunc(2.5));
  printf("trunc(%lf)=%lf\n", 2.8, trunc(2.8));
  printf("trunc(%lf)=%lf\n", -2.3, trunc(-2.3));
  printf("trunc(%lf)=%lf\n", -2.5, trunc(-2.5));
  printf("trunc(%lf)=%lf\n", -2.8, trunc(-2.8));

  printf("round(%lf)=%lf\n", 2.3, round(2.3));
  printf("round(%lf)=%lf\n", 2.5, round(2.5));
  printf("round(%lf)=%lf\n", 2.8, round(2.8));
  printf("round(%lf)=%lf\n", -2.3, round(-2.3));
  printf("round(%lf)=%lf\n", -2.5, round(-2.5));
  printf("round(%lf)=%lf\n", -2.8, round(-2.8));

  printf("lround(%lf)=%ld\n", 2.3, lround(2.3));
  printf("lround(%lf)=%ld\n", 2.5, lround(2.5));
  printf("lround(%lf)=%ld\n", 2.8, lround(2.8));
  printf("lround(%lf)=%ld\n", -2.3, lround(-2.3));
  printf("lround(%lf)=%ld\n", -2.5, lround(-2.5));
  printf("lround(%lf)=%ld\n", -2.8, lround(-2.8));

// lwml

  printf("fpr::round(%lf)=%lf\n", 2.3, fpr::round(2.3));
  printf("fpr::round(%lf)=%lf\n", 2.5, fpr::round(2.5));
  printf("fpr::round(%lf)=%lf\n", 2.8, fpr::round(2.8));
  printf("fpr::round(%lf)=%lf\n", -2.3, fpr::round(-2.3));
  printf("fpr::round(%lf)=%lf\n", -2.5, fpr::round(-2.5));
  printf("fpr::round(%lf)=%lf\n", -2.8, fpr::round(-2.8));

  printf("fpr::lround(%lf)=%d\n", 2.3, fpr::lround(2.3));
  printf("fpr::lround(%lf)=%d\n", 2.5, fpr::lround(2.5));
  printf("fpr::lround(%lf)=%d\n", 2.8, fpr::lround(2.8));
  printf("fpr::lround(%lf)=%d\n", -2.3, fpr::lround(-2.3));
  printf("fpr::lround(%lf)=%d\n", -2.5, fpr::lround(-2.5));
  printf("fpr::lround(%lf)=%d\n", -2.8, fpr::lround(-2.8));

  printf("fpr::trunc(%lf)=%lf\n", 2.3, fpr::trunc(2.3));
  printf("fpr::trunc(%lf)=%lf\n", 2.5, fpr::trunc(2.5));
  printf("fpr::trunc(%lf)=%lf\n", 2.8, fpr::trunc(2.8));
  printf("fpr::trunc(%lf)=%lf\n", -2.3, fpr::trunc(-2.3));
  printf("fpr::trunc(%lf)=%lf\n", -2.5, fpr::trunc(-2.5));
  printf("fpr::trunc(%lf)=%lf\n", -2.8, fpr::trunc(-2.8));

  printf("fpr::ltrunc(%lf)=%d\n", 2.3, fpr::ltrunc(2.3));
  printf("fpr::ltrunc(%lf)=%d\n", 2.5, fpr::ltrunc(2.5));
  printf("fpr::ltrunc(%lf)=%d\n", 2.8, fpr::ltrunc(2.8));
  printf("fpr::ltrunc(%lf)=%d\n", -2.3, fpr::ltrunc(-2.3));
  printf("fpr::ltrunc(%lf)=%d\n", -2.5, fpr::ltrunc(-2.5));
  printf("fpr::ltrunc(%lf)=%d\n", -2.8, fpr::ltrunc(-2.8));
}
