#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void print_binary(uint64_t num, uint8_t count) {
  for (uint16_t i = count; i > 0; i--) {
    if (i % 4 == 0)
      printf(" ");
    if (num >> (i - 1) & 1)
      printf("1");
    else
      printf("0");
  }
  printf("\n");
}

uint64_t double_dabble(uint64_t original) {
  // n + 4×ceil(n/3)
  uint64_t num = original;
  print_binary(num, 64);

  // Determine num original byte size
  uint8_t num_size = 0;
  for (uint8_t i = 0; i < 8; i++) {
    int index = 8 - i - 1;
    if () {
      num_size = i + 1;
      break;
    }
  }
  printf("num_size: %d\n", num_size);

  while (1) {
    num = num << 1;
    // Use i as shift position multiplier, so must be range 5-0
    for (int i = 0; i < 14; i++) {
      uint32_t shift = (2 + i) * 4;
      uint32_t digit = (num >> shift) & 0b1111;
      if (digit >= 5) {
        num += (3 << shift);
      }
    }
    print_binary(num, 64);
    if ((num & 0b11111111) == 0)
      break;
  }
  // print_binary(num, 64);
  return num >> 8;
}

int main() {
  uint16_t num = 243;
  uint64_t numbcd = double_dabble(num);
  print_binary(numbcd, 64);
  printf("\n");
  uint16_t num2 = 65244;
  uint64_t num2bcd = double_dabble(num2);
  print_binary(num2bcd, 32);
}
