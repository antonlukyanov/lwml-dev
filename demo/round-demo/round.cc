#include "mdefs.h"

using namespace lwml;

int main(){
  printf("floor(%f)=%f\n", 2.3, floor(2.3));
  printf("floor(%f)=%f\n", 2.5, floor(2.5));
  printf("floor(%f)=%f\n", 2.8, floor(2.8));
  printf("floor(%f)=%f\n", -2.3, floor(-2.3));
  printf("floor(%f)=%f\n", -2.5, floor(-2.5));
  printf("floor(%f)=%f\n", -2.8, floor(-2.8));

  printf("ceil(%f)=%f\n", 2.3, ceil(2.3));
  printf("ceil(%f)=%f\n", 2.5, ceil(2.5));
  printf("ceil(%f)=%f\n", 2.8, ceil(2.8));
  printf("ceil(%f)=%f\n", -2.3, ceil(-2.3));
  printf("ceil(%f)=%f\n", -2.5, ceil(-2.5));
  printf("ceil(%f)=%f\n", -2.8, ceil(-2.8));

  printf("trunc(%f)=%f\n", 2.3, trunc(2.3));
  printf("trunc(%f)=%f\n", 2.5, trunc(2.5));
  printf("trunc(%f)=%f\n", 2.8, trunc(2.8));
  printf("trunc(%f)=%f\n", -2.3, trunc(-2.3));
  printf("trunc(%f)=%f\n", -2.5, trunc(-2.5));
  printf("trunc(%f)=%f\n", -2.8, trunc(-2.8));

  printf("round(%f)=%f\n", 2.3, round(2.3));
  printf("round(%f)=%f\n", 2.5, round(2.5));
  printf("round(%f)=%f\n", 2.8, round(2.8));
  printf("round(%f)=%f\n", -2.3, round(-2.3));
  printf("round(%f)=%f\n", -2.5, round(-2.5));
  printf("round(%f)=%f\n", -2.8, round(-2.8));

  printf("lround(%f)=%ld\n", 2.3, lround(2.3));
  printf("lround(%f)=%ld\n", 2.5, lround(2.5));
  printf("lround(%f)=%ld\n", 2.8, lround(2.8));
  printf("lround(%f)=%ld\n", -2.3, lround(-2.3));
  printf("lround(%f)=%ld\n", -2.5, lround(-2.5));
  printf("lround(%f)=%ld\n", -2.8, lround(-2.8));

// lwml

  printf("fpr::round(%f)=%f\n", 2.3, fpr::round(2.3));
  printf("fpr::round(%f)=%f\n", 2.5, fpr::round(2.5));
  printf("fpr::round(%f)=%f\n", 2.8, fpr::round(2.8));
  printf("fpr::round(%f)=%f\n", -2.3, fpr::round(-2.3));
  printf("fpr::round(%f)=%f\n", -2.5, fpr::round(-2.5));
  printf("fpr::round(%f)=%f\n", -2.8, fpr::round(-2.8));

  printf("fpr::lround(%f)=%d\n", 2.3, fpr::lround(2.3));
  printf("fpr::lround(%f)=%d\n", 2.5, fpr::lround(2.5));
  printf("fpr::lround(%f)=%d\n", 2.8, fpr::lround(2.8));
  printf("fpr::lround(%f)=%d\n", -2.3, fpr::lround(-2.3));
  printf("fpr::lround(%f)=%d\n", -2.5, fpr::lround(-2.5));
  printf("fpr::lround(%f)=%d\n", -2.8, fpr::lround(-2.8));

  printf("fpr::trunc(%f)=%f\n", 2.3, fpr::trunc(2.3));
  printf("fpr::trunc(%f)=%f\n", 2.5, fpr::trunc(2.5));
  printf("fpr::trunc(%f)=%f\n", 2.8, fpr::trunc(2.8));
  printf("fpr::trunc(%f)=%f\n", -2.3, fpr::trunc(-2.3));
  printf("fpr::trunc(%f)=%f\n", -2.5, fpr::trunc(-2.5));
  printf("fpr::trunc(%f)=%f\n", -2.8, fpr::trunc(-2.8));

  printf("fpr::ltrunc(%f)=%d\n", 2.3, fpr::ltrunc(2.3));
  printf("fpr::ltrunc(%f)=%d\n", 2.5, fpr::ltrunc(2.5));
  printf("fpr::ltrunc(%f)=%d\n", 2.8, fpr::ltrunc(2.8));
  printf("fpr::ltrunc(%f)=%d\n", -2.3, fpr::ltrunc(-2.3));
  printf("fpr::ltrunc(%f)=%d\n", -2.5, fpr::ltrunc(-2.5));
  printf("fpr::ltrunc(%f)=%d\n", -2.8, fpr::ltrunc(-2.8));
}
