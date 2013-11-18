#include "all_modules.h"

namespace {
  #include "winbgi.h"
};

using namespace lwml;

int main( int argc, char *argv[] ){
try{
  console::init( argc, argv );

}catch( error& er ){
  console::handlex(er);
}
}
