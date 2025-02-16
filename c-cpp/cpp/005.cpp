// Smallest Multiple
// Problem 5

#include <cstdint>
#include <cstdio>

bool check_numbers(uint32_t input, uint32_t max_num) {
  for (int i = 2; i <= max_num; i++) {
    if (input % i != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int maxDivNumber = 20;
  int beginnumber = maxDivNumber * 2;
  int scratch = beginnumber;
  while (true) {
    bool res = check_numbers(scratch, maxDivNumber);
    if (res) {
      printf("brih %d %d\n", scratch, res);
      break;
    }
    scratch++;
  }
}
