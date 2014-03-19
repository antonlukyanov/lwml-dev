#include "lwml.h"

extern "C" {
#include <pthread.h>
}

int num = 100000000;

void* thread_function( void* arg )
{
  // Cast the parameter into what is needed.
  int* incoming = (int*) arg;

  // Do whatever is necessary using *incoming as the argument.
  double s = 0;
  for( int j = 0; j < num; j++ )
    s += sin(j);
  printf("main: %f\n", s);

  // The thread terminates when this function returns.
  return NULL;
}

using namespace lwml;

int main( int argc, char *argv[] ){
try{
  console::init(argc, argv);

  pthread_t thread_ID;
  void* exit_status;
  int value;

  // Put something meaningful into value.
  value = 42;

  // Create the thread, passing &value for the argument.
  pthread_create(&thread_ID, NULL, thread_function, &value);

  double s = 0;
  for( int j = 0; j < num; j++ )
    s += sin(j);
  printf("main: %f\n", s);

  // The main program continues while the thread executes.
  // Wait for the thread to terminate.
  pthread_join(thread_ID, &exit_status);

}catch( error& err ){
  console::handlex(err);
}
}
