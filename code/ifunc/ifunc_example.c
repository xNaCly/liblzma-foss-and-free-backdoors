#include <stdio.h>
#include <stdlib.h>

void generic_function_linux() { puts("linux"); }

void generic_function_windows() { puts("windows"); }

void (*select_generic_function())() {
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
  generic_function();
  return EXIT_SUCCESS;
}
