#include <stdio.h>

int my_pow(int x, int y) {
  int res = 1;
  for (int i = 0; i < y; i++) res *= x;
  return res;
}

int main() {
  for (int k = 2; k < 6; k++)
    printf("%d ** %d = %d\n", k, k + 1, my_pow(k, k + 1));
}