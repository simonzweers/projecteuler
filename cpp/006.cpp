// Problem 6
// Sum Square Difference

#include <cstdio>

int sumSquares(int n) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += i * i;
	}
	return ret;
}

int squaredSum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += i;
	}
	ret *= ret;
	return ret;
}

int main() {
	int n = 100;

	int sumSq = sumSquares(n);
	int sqSum = squaredSum(n);
	printf("sumSqaures %d\n", sumSq);
	printf("squaredSum %d\n", sqSum);
	printf("diff %d\n", sqSum - sumSq);

	return 0;
}

