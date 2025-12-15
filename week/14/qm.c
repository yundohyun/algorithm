#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

void quick(int a[], int left, int right) {
  if (left < right) {
    int i = left, j = right + 1, pivot = a[left];
    while (i < j) {
      do i++; while (a[i] <= pivot && i < right);
      do j--; while (a[j] >= pivot && j > left);
    }
    if (i < j) {
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
    if (j != left) {
      int tmp = a[j];
      a[j] = a[left];
      a[left] = tmp;
    }
    quick(a, left, j - 1);
    quick(a, j + 1, right);
  }
}

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

int main() {
  int n1;
  printf("Input Data Length : ");
  scanf("%d", &n1);

  int list1[n1];
  printf("Enter %d data:\n", n1);
  for (int i = 0; i < n1; i++) scanf("%d", &list1[i]);
  quick(list1, 0, n1 - 1);
  printf("정렬된 데이터 집합 : \n");
  for (int i = 0; i < n1; i++) printf("%d ", list1[i]);
  printf("\n\n");

  int n2;
  printf("Input Data Length : ");
  scanf("%d", &n2);

  int list2[n2];
  printf("Enter %d data:\n", n2);
  for (int i = 0; i < n2; i++) scanf("%d", &list2[i]);
  merge_sort(list1, 0, n1 - 1);
  printf("정렬된 데이터 집합 : \n");
  for (int i = 0; i < n1; i++) printf("%d ", list1[i]);
  printf("\n\n");
}
