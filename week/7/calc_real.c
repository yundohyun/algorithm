#include <stdio.h>
#include <math.h>
#define STAGE1 0
#define STAGE2 1
#define STAGE3 2

void double_calculator();
double double_operation(char op, double op1, double op2);
double get_double(double current_operand, char c, int status);
int is_operator(char c);
int is_digit(char c);

int main() {
  printf("실수 계산기 실행 (종료: x)\n");
  printf("예: 22.0*4.0[Enter], 다음 연산 계속 가능\n\n");
  double_calculator();
  printf("계산기 종료");
  return 0;
}

void double_calculator() {
  double operand1 = 0, operand2 = 0, result = 0;
  int current_stage = STAGE1, status = 0;
  char op = 0;

  char c = getchar();
  while (c != 'x') {
    if (current_stage == STAGE1) {
      if (is_digit(c)) {
        operand1 = get_double(operand1, c, status);
        if (status != 0) status++;
      } else if (c == '.') status = 1;
      else if (is_operator(c)) {
        op = c;
        status = 0;
        current_stage = STAGE2;
        operand2 = 0;
      }
    } else if (current_stage == STAGE2) {
      if (is_digit(c)) {
        operand2 = get_double(operand2, c, status);
        if (status != 0) status++;
      } else if (c == '.') status = 1;
      else if (c == '\n') {
        result = double_operation(op, operand1, operand2);
        printf("= %g", result);
        operand1 = result;
        current_stage = STAGE3;
      }
    } else if (current_stage == STAGE3) {
      if (is_operator(c)) {
        op = c;
        status = 0;
        current_stage = STAGE2;
        operand2 = 0;
      } else if (is_digit(c)) {
        operand1 = get_double(operand1, c, status);
        if (status != 0) status++;
        current_stage = STAGE1;
      } else if (c == '.') status = 1;
      else if (c == '\n') {
        current_stage = STAGE1;
        operand1 = 0;
        status = 0;
      }
    }
    c = getchar();
  }
}

double double_operation(char op, double op1, double op2) {
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
    double res = 1;
    for (int i = 0; i < op2; i++) res *= op1;
    return res;
  }
  default:
    printf("알 수 없는 연산자: %c\n", op);
    return 0;
  }
}

double get_double(double current_operand, char c, int status) {
  int p1;
  double p2;
  if (status == 0) {
    p1 = c - '0';
    current_operand *= 10;
    current_operand += p1;
  } else {
    p2 = c - '0';
    p2 = p2 * pow(10, -status);
    current_operand += p2;
  }
  return current_operand;
}

int is_operator(char c) {
  return c == '*' || c == '/' || c == '+' || c == '-' || c == '^';
}

int is_digit(char c) {
  return c >= '0' && c <= '9';
}
