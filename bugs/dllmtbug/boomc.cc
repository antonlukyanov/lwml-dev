#include <windows.h>

/*
//part of the workaround
extern "C" __attribute__((dllexport)) void call_instance_of_cpp_runtime_from_exe()
{
  static volatile int i = 0;
  try{ throw i; }catch(int x){ i = 1;}
}
*/

int main(int argc, char **argv)
{
/*
This is workaround for the bug
Every thread that uses exceptions must make first use of exceptions 
from a code that resides in exe 
(or another module that lives in the process address space 
as long as mingwm10.dll or longer). 
*/
//  int (*fooptr)() = (int(*)())GetProcAddress( GetModuleHandle(NULL), "call_instance_of_cpp_runtime_from_exe" );
//  fooptr();

  typedef int (*boom_t)();
  HINSTANCE lib = LoadLibrary("boom.dll");
  boom_t boom = (boom_t)GetProcAddress(lib, "boom");
  boom();
  FreeLibrary(lib);
//  uncomment the line below to reproduce the bug
//  move this line to the position before the LoadLibrary call to get rid of the bug 
//  try{ throw 0; }catch(...){return 1;}

  return 0;

//another way to reproduce the bug (making sure that mingwm10.dll is used by the exe)
//  extern "C"  int __mingwthr_key_dtor (DWORD key, void (*dtor) (void *)); 
//  return (int)__mingwthr_key_dtor;
}
