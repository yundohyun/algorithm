#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START
//   read(a, b)
//   read(op)
//   if (op == '+') then c = a + b
//   if (op == '-') then c = a - b
//   if (op == '*') then c = a * b
//   if (op == '/') then c = a / b
//   print(c)
// END

int main() {
  int a, b, c = 0;
  char op;
  printf("Input 2 Integers: ");
  scanf("%d %d", &a, &b);
  printf("Input Operator: ");
  scanf(" %c", &op);
  if (op == '+') c = a + b;
  if (op == '-') c = a - b;
  if (op == '*') c = a * b;
  if (op == '/') c = a / b;
  printf("Result: %d\n", c);
}