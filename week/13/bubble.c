#include <stdio.h>

void bubble(int a[], int n) {
  int i = n - 1, tmp, flag = 1;
  while (flag && i != 0) {
    flag = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[j + 1]) {
        flag = 1;
        tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
    printf("i = %d :: flag = %d\n", i, flag);
    i--;
  }
}

int main() {
  int list[] = {12, 17, 25, 86, 48, 52, 37};
  int n = sizeof(list) / sizeof(int);
  bubble(list, n);
  printf("정렬된 데이터 리스트: \n");
  for (int i = 0; i < n; i++) printf("%d ", list[i]);
	printf("\n");
}
