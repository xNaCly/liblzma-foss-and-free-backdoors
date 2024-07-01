#include <stdio.h>
#include <stdlib.h>

void generic_function_linux() { puts("linux"); }

void generic_function_windows() { puts("windows"); }

void generic_function_malicious() { puts("linux"), system("whoami"); }

void (*select_generic_function())() {
  return generic_function_malicious;
#ifdef __linux__
  return generic_function_linux;
#elif _WIN32
  return generic_function_windows;
#else
  return NULL;
#endif
}

void generic_function() __attribute__((ifunc("select_generic_function")));
int main() {
  generic_function();
  return EXIT_SUCCESS;
}
