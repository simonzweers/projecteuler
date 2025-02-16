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
    /*
if () {
  num_size = i + 1;
  break;
}
    */
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

uint32_t get_bcd(uint32_t decimal) {
  uint32_t ret = 0;
  uint8_t shift = 0;

  while (decimal > 0) {
    ret |= (decimal % 10) << (shift++ * 4);
    decimal /= 10;
  }
  return ret;
}

int main() {
  uint32_t num1 = get_bcd(243);
  print_binary(num1, 32);
  uint32_t num2 = get_bcd(65244);
  print_binary(num2, 32);
}
