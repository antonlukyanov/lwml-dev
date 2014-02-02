#include <windows.h>

int main(int argc, char **argv)
{
  typedef int (*boom_t)();
  HINSTANCE lib = LoadLibrary("rethrow.dll");
  boom_t boom = (boom_t)GetProcAddress(lib, "boom");
  try
  {
	   throw 42; 
	}
	catch(...)
	{
    //try{ throw; } catch(...){ return 1;}
	  boom();
    return 1;
	}
  FreeLibrary(lib);
  return 0;
}
