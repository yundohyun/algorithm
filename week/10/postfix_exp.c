#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>

int stack[MAX_SIZE];
int top = -1;
char pexpr[MAX_SIZE];

void add_stack(int item) {
  stack[++top] = item;
}

int delete_stack() {
  if (top == -1) return -1;
  return stack[top--];
}

int is_operator(char symbol) {
  return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int calc() {
  char symbol;
  int op1, op2, n = 0;
    
  top = -1;
  symbol = pexpr[n++];

  while (symbol != '\0') {
    if (is_operator(symbol)) {
      op2 = delete_stack();
      op1 = delete_stack();
      switch (symbol) {
        case '+': add_stack(op1 + op2); break;
        case '-': add_stack(op1 - op2); break;
        case '/': add_stack(op1 / op2); break;
        case '*': add_stack(op1 * op2); break;
      }
    } else add_stack(symbol - '0');
    symbol = pexpr[n++];
  }

  return delete_stack();
}

int main() {
  printf("--- 후위 표기식 계산기 ---\n");
    
  while (1) {
    printf("\n수식 입력 (예: 34+2*): ");
    scanf("%s", pexpr);
    printf("계산 결과: %d\n", calc());
  }
}