// Smallest Multiple
// Problem 5

#include <cstdint>
#include <cstdio>

int main() {
    int maxDivNumber = 10;
    int beginnumber = maxDivNumber * 2;
    while (true) {
        // Check all numbers from 1 to maxDivNumber for division
        for (int i = 1; i <= maxDivNumber; i++) {
            if (beginnumber % i == 0) {
                printf("sdaw");
            }
        }
    }
}