#include <stdio.h>
#include <stdlib.h>

int generic_function_linux() { return 1; }

int generic_function_windows() { return 2; }

int (*select_generic_function())() {
#ifdef __linux__
  return generic_function_linux;
#elif _WIN32
  return generic_function_windows;
#else
  return NULL;
#endif
}

int generic_function() __attribute__((ifunc("select_generic_function")));
int main() {
  printf("Result: %d\n", generic_function());
  return EXIT_SUCCESS;
}
