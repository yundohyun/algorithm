#include <stdio.h>
#define STAGE1 0
#define STAGE2 1
#define STAGE3 2

// 자료구조 플러스 338 ~ 339쪽
// 상태도 분석 기법을 이용한 계산기

void int_calculator();
int int_operation(char op, int op1, int op2);
int get_int(int current_operand, char c);
int is_operator(char c);
int is_digit(char c);

int main() {
  printf("정수 계산기 실행 (종료: x)\n");
  printf("예: 22*4[Enter], 다음 연산 계속 가능\n\n");
  int_calculator();
  printf("계산기 종료");
  return 0;
}

void int_calculator() {
  int operand1 = 0, operand2 = 0, result = 0;
  int current_stage = STAGE1;
  char op = 0;

  char c = getchar();
  while (c != 'x') {
    if (current_stage == STAGE1) {
      if (is_digit(c)) {
        operand1 = get_int(operand1, c);
      } else if (is_operator(c)) {
        op = c;
        current_stage = STAGE2;
        operand2 = 0;
      }
    } else if (current_stage == STAGE2) {
      if (is_digit(c)) {
        operand2 = get_int(operand2, c);
      } else if (c == '\n') {
        result = int_operation(op, operand1, operand2);
        printf("= %d", result);
        operand1 = result;
        current_stage = STAGE3;
      }
    } else if (current_stage == STAGE3) {
      if (is_operator(c)) {
        op = c;
        current_stage = STAGE2;
        operand2 = 0;
      } else if (is_digit(c)) {
        operand1 = get_int(operand1, c);
        current_stage = STAGE1;
      } else if (c == '\n') {
        current_stage = STAGE1;
        operand1 = 0;
      }
    }
    c = getchar();
  }
}

int int_operation(char op, int op1, int op2) {
  switch (op) {
  case '+': return op1 + op2;
  case '-': return op1 - op2;
  case '*': return op1 * op2;
  case '/':
    if (op2 == 0) {
      printf("오류: 0으로 나눌 수 없습니다.\n");
      return 0;
    }
    return op1 / op2;
  case '^': {
    int res = 1;
    for (int i = 0; i < op2; i++) res *= op1;
    return res;
  }
  default:
    printf("알 수 없는 연산자: %c\n", op);
    return 0;
  }
}

int get_int(int current_operand, char c) {
  return current_operand * 10 + (c - '0');
}

int is_operator(char c) {
  return c == '*' || c == '/' || c == '+' || c == '-' || c == '^';
}

int is_digit(char c) {
  return c >= '0' && c <= '9';
}
