#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pcount(int a[], int n) {
  int res = 0;
  for (int i = 0; i < 10; i++)
    if (a[i] > 0) res++;
  return res;
}

int large(int a[], int n) {
  int res = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > res) res = a[i];
  return res;
}

int small(int a[], int n) {
  int res = 25565;
  for (int i = 0; i < n; i++)
    if (a[i] < res) res = a[i];
  return res;
}

double avg(int a[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  return (double) sum / n;
}

int main() {
  int n;
  printf("Input Integer Length: ");
  scanf("%d", &n);
  int data[n];
  printf("Input %d Integers\n", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &data[i]);
  printf("양의 개수: %d\n", pcount(data, n));
  printf("Avg: %.2lf\n", avg(data, n));
  printf("Largest Integer: %d\n", large(data, n));
  printf("Smallest Integer: %d\n", small(data, n));
}