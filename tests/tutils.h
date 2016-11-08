// Simple utils for testing
// lwml, (c) ltwood

#ifndef _TUTILS_
#define _TUTILS_

#include "lwml/base/defs.h"
#include "lwml/m_base/mdefs.h"

/*#lake:stop*/

namespace lwml_test {

using namespace lwml;

class test_state  : public value {
public:
  test_state() : _state(true) {}

  void up( bool v ) {
    if( !v )
      _state = false;
  }

  bool get() const { return _state; }

private:
  bool _state;
};


}; // namespace lwml_test

#endif // _TUTILS_
