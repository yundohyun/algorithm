#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_data(int list[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", list[i]);
  printf("\n");
}

void selection_sort(int list[], int n, int log) {
	int m, tmp;
  if (log != 0) printf("---- asc sort log ----\n");
	for (int i = 0; i < n - 1; i++) {
		m = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[m]) m = j;
		tmp = list[i];
		list[i] = list[m];
		list[m] = tmp;
    if (log != 0) print_data(list, n);
	}
  if (log != 0) printf("---- asc sort log ----\n");
}

void selection_sort_desc(int list[], int n, int log) {
	int m, tmp;
  if (log != 0) printf("---- desc sort log ----\n");
	for (int i = 0; i < n - 1; i++) {
		m = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] > list[m]) m = j;
		tmp = list[i];
		list[i] = list[m];
		list[m] = tmp;
    if (log != 0) print_data(list, n);
	}
  if (log != 0) printf("---- desc sort log ----\n");
}

int main() {
  int n;
  printf("Input Integer Length: ");
  scanf("%d", &n);
  int data[n], data2[n];

  printf("Input %d Integers\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
    data2[i] = data[i];
  }

  selection_sort(data, n, 1);

  printf("ASC Sort Result:\n");
  print_data(data, n);

  selection_sort_desc(data2, n, 1);

  printf("DESC Sort Result:\n");
  print_data(data2, n);
}