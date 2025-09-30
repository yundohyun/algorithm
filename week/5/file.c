#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main(int argc, char *argv[]) {
  int a, b;
  int cor = 0, i = 0;
  FILE *file, *out;

  if (argc != 3) {
    printf("실행 인수 잘못됨\n");
    exit(1);
  }

  if ((file = fopen(argv[1], "r")) == NULL) {
    printf("파일 읽기 오류\n");
    exit(1);
  }

  if ((out = fopen(argv[2], "w")) == NULL) {
    printf("출력 파일을 만들 수 없습니다\n");
    exit(1);
  }

  while (fscanf(file, "%d %d", &a, &b) != EOF) {
    printf("%d: gcd(%d, %d) = ", ++i, a, b);
    int ans, res = gcd(a, b);
    scanf("%d", &ans);
    if (ans != res) {
      printf("Answer: gcd(%d, %d) = %d\n", a, b, res);
      fprintf(out, "%d %d\n", a, b);
    } else {
      printf("Correct!\n");
      cor++;
    }
  }

  printf("Score: %.0lf (%d / %d)\n", (double) cor / i * 100, cor, i);
}