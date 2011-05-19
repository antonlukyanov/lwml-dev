#include "lwml.h"

#include "mcontr.h"
#include "vbmp.h"

using namespace lwml;

int main( int argc, char *argv[] ){
try{
  console::init( argc, argv );

  vbmp bmp(console::argv().ascstr());
  matrix src(bmp.ly(), bmp.lx());
  bmp.get(src);

  real par = config()->get_real("par");
  real sh = config()->get_real("sh");

  matrix src_dc(src);
  matrix src_uc(src);

  mcontr::decontr(src_dc, par, sh);
  mcontr::upcontr(src_uc, par, sh);

  vbmp::save("decontr.bmp", src_dc);
  vbmp::save("upcontr.bmp", src_uc);

/*
  matrix dst2(k*bmp.ly(), k*bmp.lx());
  for( int s = 0; s < dst2.str(); s++ ){
    real rs = scale::coord(s, 0, dst2.str()-1, 0, src.str()-1);
    for( int c = 0; c < dst2.col(); c++ ){
      real rc = scale::coord(c, 0, dst2.col()-1, 0, src.col()-1);
      dst2(s, c) = lanczos::calc(src, rs, rc, r);
    }
  }
  vbmp::save("resamp2.bmp", dst2);
*/

}catch( error& er ){
  console::handlex(er);
}
}
