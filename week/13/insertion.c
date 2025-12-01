#include <stdio.h>

void insertion(int a[], int n) {
	int key;
	for (int i = 1; i < n; i++) {
		key = a[i];
		int j = i - 1;
		while (a[j] > key && j >= 0) {
			a[j + 1] = a[j];
      j--;
    }
		a[j + 1] = key;
	}
}

int main() {
  int list[] = {12, 17, 25, 86, 48, 52, 37};
  int n = sizeof(list) / sizeof(int);
  insertion(list, n);
  printf("정렬된 데이터 리스트: \n");
  for (int i = 0; i < n; i++) printf("%d ", list[i]);
	printf("\n");
}