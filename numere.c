#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NUMBERS 10000

int main() {
  int i;
  srand(time(NULL)); // Seed the random number generator with the current time
  for (i = 0; i < NUM_NUMBERS; i++) {
    printf("%d", rand() % 1000);
    if (i < NUM_NUMBERS - 1) {
      printf(", ");
    }
  }
  return 0;
}
