#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pcount(int a[]) {
  int res = 0;
  for (int i = 0; i < 10; i++)
    if (a[i] > 0) res++;
  return res;
}

int main() {
  int data[10];
  printf("Input 10 Integers: \n");
  for (int i = 0; i < 10; i++)
    scanf("%d", &data[i]);
  printf("양의 개수: %d\n", pcount(data));
}