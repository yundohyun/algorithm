#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int merge(int list1[], int list2[], int result[], int n1, int n2) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n1 && j < n2) {
    if (list1[i] <= list2[j]) result[k++] = list1[i++];
    else result[k++] = list2[j++];
  }
  while (i < n1)  result[k++] = list1[i++];
  while (j < n2) result[k++] = list2[j++];
  return n1 + n2;
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
  int list1[] = {10, 20, 30, 40, 50, 60, 70, 77, 80, 90};
  int list2[] = {25, 27, 35, 38, 40};
  int list3[] = {15, 45, 47, 57, 59};
  int list4[] = {1, 2, 5, 9, 60, 62, 65, 67, 69};
  int res1[50], res2[50], res3[100];

  int n1 = sizeof(list1) / sizeof(int);
  int n2 = sizeof(list2) / sizeof(int);
  int n3 = sizeof(list3) / sizeof(int);
  int n4 = sizeof(list4) / sizeof(int);

  int rn1 = merge(list1, list2, res1, n1, n2);
  print_list(res1, rn1, "중간 데이터 리스트 1:");
  int rn2 = merge(list3, list4, res2, n3, n4);
  print_list(res2, rn2, "중간 데이터 리스트 2:");
  int rn3 = merge(res1, res2, res3, rn1, rn2);
  print_list(res3, rn3, "최종 데이터 리스트:");
}