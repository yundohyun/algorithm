#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	int a, b, repeat = 1;
	while (repeat) {
    printf("최대공약수를 구할 두 수 입력: ");
    scanf("%d %d", &a, &b);
    if (a == 0 && b == 0) break;
    int result = gcd(a, b);
    printf("gcd(%d, %d) = %d\n", a, b, result);
	}
}
