#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* magic_square(int n) {
	int* table = calloc(n * n, sizeof(int));
	int x = (n - 1) / 2, y = 0;
	for (int i = 1; i <= n * n; i++) {
		*(table + x + y * n) = i;
		int next_x = (x - 1 + n) % n;
    int next_y = (y - 1 + n) % n;
    if (*(table + next_x + next_y * n) == 0) {
    	x = next_x;
    	y = next_y;
    } else y = (y + 1) % n;
	}
	return table;
}

void print_magic_square(int* table, int n) {
	int width = 0, tmp = n * n * 10;
	while ((tmp /= 10) != 0) width++;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) printf(" %*d", width, *(table + x + y * n));
		printf("\n");
	}
}

int main() {
	int n;
	printf("Input a number: ");
	scanf("%d", &n);
	while (n % 2 == 0 || n < 1) {
		printf("Please input odd number.\n");
		printf("Input a number: ");
		scanf("%d", &n);
	}
	int* result = magic_square(n);
	print_magic_square(result, n);
	free(result);
}