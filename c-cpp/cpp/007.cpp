#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;

bool isPrime(uint64_t input) {
  // uint64_t maxDiv = input / 2;
  // uint64_t maxDiv = (uint64_t)sqrt((double)input) + 1;
  uint64_t maxDiv = input;

  if (input <= 3) {
    return true;
  }
  for (uint64_t i = 2; (i * i) <= maxDiv; i++) {
    // printf("num %d  mod %d \n", input, input % i);
    if (input % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  auto t1 = high_resolution_clock::now();

  int n = 2;
  int k = 0;
  while (true) {
    if (isPrime(n)) {
      k++;
    }
    if (k == 10001) {
      break;
    }
    // printf("k: %d\n", k);
    // printf("n: %d\n", n);
    n++;
  }
  auto t2 = high_resolution_clock::now();

  auto ms_int = duration_cast<nanoseconds>(t2 - t1);
  printf("duration %ldns\n", ms_int.count());

  printf("10001st prime num: %d\n", n);
}
