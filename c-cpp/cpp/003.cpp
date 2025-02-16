#include <cstdint>
#include <cstdio>

bool isPrime(uint64_t input) {
    uint64_t halfInput = input / 2;
    if (input <= 3) {
        return true;
    }
    for (uint64_t i = 2; i < halfInput + 1; i++) {
        // printf("num %d  mod %d \n", input, input % i);
        if (input % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Hello World\n");
    uint64_t inputOriginal = 600851475143;
    // int inputOriginal = 13195;
    uint64_t input = inputOriginal;
    uint64_t hafInput = input / 2;

    uint64_t primeFactor = 0;
    for (uint64_t i = 2; i < hafInput; i++) {
        if (isPrime(i)) {
            // found next prime factor

            if (input % i == 0) {
                // if input is divisible by prime factor
                std::printf("factor found: %ld\n", i);
                input /= i;
                if (input < i) {
                    primeFactor = i;
                    break;
                }
            }
        }
        printf("num: %ld is prime: %ld\n", i, isPrime(i));
    }

    printf("Found largest prime factor %ld\n", primeFactor);
}
