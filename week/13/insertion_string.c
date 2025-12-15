#include <stdio.h>
#include <string.h>

void insertion_string(char a[][10], int n) {
	char key[10];
	for (int i = 1; i < n; i++) {
		strcpy(key, a[i]);
		int j = i - 1;
		while (strcmp(a[j], key) > 0 && j >= 0) {
			strcpy(a[j + 1], a[j]);
			j--;
		}
		strcpy(a[j + 1], key);
	}
}

int main() {
  char list[][10] = {"name", "is", "soo", "hyong", "my"};
  int n = sizeof(list) / sizeof(list[0]);
  insertion_string(list, n);
  printf("정렬된 데이터 리스트: \n");
  for (int i = 0; i < n; i++) printf("%s ", list[i]);
	printf("\n");
}
