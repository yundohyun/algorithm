#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

void merge(int list[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	int tlist[MAX_SIZE];
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			tlist[k] = list[i];
			i++;
		  k++;
		} else {
			tlist[k] = list[j];
			j++;
		  k++;
		}
	}
	if (i > mid) while (j <= right) tlist[k++] = list[j++];
	else while (i <= mid) tlist[k++] = list[i++];
	for (int l = left; l <= right; l++) list[l] = tlist[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

void merge_descending(int list[], int left, int mid, int right) {
  int i = left, j = mid + 1, k = left;
  int tlist[MAX_SIZE]; 
  while (i <= mid && j <= right) {
    if (list[i] >= list[j]) { 
      tlist[k++] = list[i++];
    } else {
      tlist[k++] = list[j++];
    }
  }
  while (i <= mid) tlist[k++] = list[i++];
  while (j <= right) tlist[k++] = list[j++];
  for (int l = left; l <= right; l++) {
    list[l] = tlist[l];
  }
}

void merge_sort_descending(int list[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort_descending(list, left, mid);
    merge_sort_descending(list, mid + 1, right);
    merge_descending(list, left, mid, right);
  }
}

void print_list(int list[], int n, char *msg) {
  printf("%s\n", msg);
  for (int i = 0; i < n; i++) {
    printf("%d    ", list[i]);
    if (i % 7 == 6) printf("\n");
  }
  printf("\n\n");
}

int main() {
  int list[] = {32, 15, 20, 55, 40, 10, 27, 30, 70, 60, 50, 90, 66, 33};
  int n = sizeof(list) / sizeof(int);

  print_list(list, n, "데이터 리스트 : ");
  merge_sort(list, 0, n - 1);
  print_list(list, n, "합병된 데이터 리스트 : ");
  merge_sort_descending(list, 0, n - 1);
  print_list(list, n, "합병된 데이터 리스트 (내림차순): ");
}
