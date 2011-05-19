//#include "basex.h"

extern "C" __attribute__((dllexport)) int boom()
{
  try{ throw 3; }catch(...){ return 1;}
//  try{ lwml::runtime("foo"); }catch(...){ return 1;}
  return 2;
}

