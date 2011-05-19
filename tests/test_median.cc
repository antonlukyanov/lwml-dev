#include "test_median.h"

#include "medianfilt.h"
#include "frand.h"

/*#lake:stop*/

namespace lwml_test {

const int lx = 35;
const int ly = 67;
const int apt = 7;

bool test_median(){
  int_matrix data(ly, lx);

  frand rnd;
  for( int y = 0; y < ly; ++y ){
    for( int x = 0; x < lx; ++x )
      data(y, x) = rnd.get_int(1234);
  }

  int_matrix res(ly, lx);
  int_matrix res_t(ly, lx);

  medianfilt::calc(res_t, data, apt);
  medianfilt::calc_test(res, data, apt);

  int err = 0;
  for( int y = 0; y < res.str(); ++y ){
    for( int x = 0; x < res.col(); ++x ){
      err += labs(res(y, x) - res_t(y, x));
    }
  }
  return err == 0;
}

}; // namespace lwml_test
