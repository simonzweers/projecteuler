#include <stdio.h>
#include <time.h>
int fibsum1() {
  int first = 0;
  int second = 1;
  int res = 0;
  int sum = 0;
  while (res < 4000000) {
    res = first + second;
    first = second;
    second = res;
    if (res % 2 == 0) {
      sum += res;
    }
  }
  return sum;
}

int fibsum2() {
  int nums[2] = {0, 1};
  int sum = 0;
  while (1) {
    nums[0] = nums[0] + nums[1];
    if (nums[0] % 2 == 0) {
      sum += nums[0];
    }
    if (nums[0] > 4000000)
      break;
    nums[1] = nums[0] + nums[1];
    if (nums[1] % 2 == 0) {
      sum += nums[1];
    }
    if (nums[1] > 4000000)
      break;
  }
  return sum;
}

int main() {
  time_t before = clock();
  int solulu1 = fibsum1();
  time_t after1 = clock() - before;

  before = clock();
  int solulu2 = fibsum2();
  time_t after2 = clock() - before;
  printf("fibsum1: %d %ld\n", solulu1, after1);
  printf("fibsum2: %d %ld\n", solulu2, after2);
}
