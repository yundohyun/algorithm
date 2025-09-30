#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hanoi(int n, char a, char b, char c) {
  int move = 0;
  if (n == 1) {
    printf("Move disk from \'%c\' to \'%c\'\n", a, c);
    move++;
  } else {
    move += hanoi(n - 1, a, b, c);
    move += hanoi(1, a, c, b);
    move += hanoi(n - 1, b, c, a);
  }
  printf("%d\n", move);
  return move;
}

int main() {
  int n;
  printf("원반의 개수: ");
  scanf("%d", &n);
  if (n <= 0) printf("너무 작습니다.\n");
  else {
    int move = hanoi(n, 'A', 'B', 'C'); 
    printf("총 움직임: %d\n", move);
  } 
}
