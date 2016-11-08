#include "tests/test_rfft.h"

#include "tests/tutils.h"

#include "lwml/fourier/fft.h"
#include "lwml/fourier/rfft.h"
#include "lwml/random/frand.h"
#include "lwml/utils/debug.h"

/*#lake:stop*/

namespace lwml_test {

const int len = 1024;

bool test_rfft2(){
  frand rnd;

  vector a0(len), a(len), x1r(len), x1i(len);
  vector b0(len), b(len), x2r(len), x2i(len);
  for( int  j = 0; j < len; j++ ){
    x1r[j] = a0[j] = a[j] = rnd.get_real();
    x1i[j] = 0.0;
    x2r[j] = b0[j] = b[j] = rnd.get_real();
    x2i[j] = 0.0;
  }

  fft::cfft(x1r, x1i);
  fft::cfft(x2r, x2i);
  rfft::rcfft2(a, b);

  real err1 = 0.0;
  err1 += fabs(x1r[0] - a[0]) + fabs(x1r[len/2] - b[0]);
  err1 += fabs(x2r[0] - a[len-1]) + fabs(x2r[len/2] - b[len-1]);
  for( int  j = 1; j < len/2; j++ ){
    err1 += (cmplx(x1r[j], x1i[j]) - cmplx(a[j], b[j])).norm();
    err1 += (cmplx(x2r[j], x2i[j]) - cmplx(a[len-1 - j], b[len-1 - j])).norm();
  }
  err1 /= len;

  zzz("rfft: rcfft2_error=%g", err1);

  rfft::crifft2(a, b);
  real err2 = 0.0;
  for( int  j = 0; j < len; j++ )
    err2 += fabs(a[j] - a0[j]) - fabs(b[j] - b0[j]);
  err2 /= len;

  zzz("rfft: crifft2_error=%g", err2);

  return err1 < 1e-15 && err2 < 1e-15;
}

bool test_rfft1(){
  frand rnd;

  vector x00(len/2), x01(len/2), xr(len), xi(len);
  vector x2r(len/2), x2i(len/2);
  for( int  j = 0; j < len; j++ ){
    real v = rnd.get_real();
    xr[j] = v;
    xi[j] = 0.0;
    if( j % 2 == 0 )
      x00[j/2] = x2r[j/2] = v;
    else
      x01[j/2] = x2i[j/2] = v;
  }

  fft::cfft(xr, xi);
  rfft::rcfft(x2r, x2i);

  real err1 = 0.0;
  err1 += fabs(x2r[0] - xr[0]);
  err1 += fabs(x2i[0] - xr[len/2]);
  for( int  j = 1; j < len/2; j++ )
    err1 += (cmplx(x2r[j], x2i[j]) - cmplx(xr[j], xi[j])).norm();
  err1 /= len;

  zzz("rfft: rcfft_error=%g", err1);

  rfft::crifft(x2r, x2i);

  real err2 = 0.0;
  for( int  j = 0; j < len/2; j++ )
    err2 += fabs(x2r[j] - x00[j]) + fabs(x2i[j] - x01[j]);
  err2 /= len;

  zzz("rfft: crifft_error=%g", err2);

  return err1 < 1e-15 && err2 < 1e-15;
}

bool test_rfft(){
  test_state st;
  st.up(test_rfft2());
  st.up(test_rfft1());
  return st.get();
}

}; // namespace lwml_test
