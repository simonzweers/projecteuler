#include <cstdio>

bool isPrime(int input) {
    int halfInput = input / 2;
    if (input <= 3) {
        return true;
    }
    for (size_t i = 2; i < halfInput + 1; i++) {
        // printf("num %d  mod %d \n", input, input % i);
        if (input % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Hello World\n");
    int inputOriginal = 13195;
    int input = inputOriginal;

    int prime = 2;
    for (int i = 1; i < 100; i++) {
        printf("num: %d is prime: %d\n", i, isPrime(i));
    }
}
