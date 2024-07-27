#include <stdint.h>
#include <stdio.h>
int main() {
  uint32_t sum = 0;
  for (uint32_t i = 1; i < 1000; i++) {
    if ((i % 3) == 0 || (i % 5) == 0) {
      printf("%d, ", i);
      sum += i;
    }
  }
  printf("\nSum: %d\n", sum);
}
