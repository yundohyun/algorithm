#include <stdio.h>

void quick(int a[], int left, int right) {
  if (left < right) {
    int i = left, j = right + 1, pivot = a[left];
    while (i < j) {
      do i++; while (a[i] >= pivot && i < right);
      do j--; while (a[j] <= pivot && j > left);
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