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

uint64_t get_bcd(uint16_t original) {
  // n + 4×ceil(n/3)
  uint64_t num = original;

  while (1) {
    num = num << 1;
    // Use i as shift position multiplier, so must be range 5-0
    for (int i = 5; i >= 0; i--) {
      uint32_t shift = (2 + i) * 4;
      uint8_t digit = (num >> shift) & 0b1111;
      if (digit >= 5) {
        num += (3 << shift);
      }
    }
    // print_binary(num, 32);
    if ((num & 0b11111111) == 0)
      break;
  }
  // print_binary(num, 64);
  return num >> 8;
}

int main() {
  uint16_t num = 243;
  uint64_t numbcd = get_bcd(num);
  print_binary(numbcd, 32);

  uint16_t num2 = 65244;
  uint64_t num2bcd = get_bcd(num2);
  print_binary(num2bcd, 32);
}
