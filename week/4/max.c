#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START
// 	max = 0, size = 0
// 	read(num)
// 	while (num >= 0) do
// 		size = size + 1
// 		if (num > max) max = num
// 		read(num)
// 	endwhile
// 	print(size)
// 	if (size == 0) print("no data")
// 	else print(max)
// END

int main() {
	int max = 0, size = 0, num;
	printf("Input Integer: ");
	scanf("%d", &num);
	while (num >= 0) {
		size++;
		if (num > max) max = num;
		printf("Input Integer: ");
		scanf("%d", &num);
	}
	printf("Data Count: %d\n", size);
	if (size == 0) printf("No Data\n");
  else printf("Max Integer Value: %d\n", max);
}