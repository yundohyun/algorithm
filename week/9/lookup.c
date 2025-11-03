#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int get_item_data(int (*data)[2], char* file_name) {
  int a, b, size = 0;
  FILE *file;

  if ((file = fopen(file_name, "r")) == NULL) {
    printf("파일 읽기 오류\n");
    exit(1);
  }

  while (fscanf(file, "%d %d", &a, &b) != EOF) {
    size++;
    data[size][0] = a;
    data[size][1] = b;
  }

  return size;
}

int calc_item_price(int (*data)[2], int n, int code, int num) {
  for (int i = 0; i < n; i++)
    if (data[i][0] == code)
      return data[i][1] * num;
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("실행 인수 잘못됨\n");
    exit(1);
  }

  int data[MAX_SIZE][2];
  int size = get_item_data(data, argv[1]);
  int len, code, num, total = 0;

  printf("팔린 물품의 종류: ");
  scanf("%d", &len);

  for (int i = 0; i < len; i++) {
    printf("물품코드와 판매갯수 입력: ");
    scanf("%d %d", &code, &num);
    int price = calc_item_price(data, size, code, num);
    if (price == -1) {
      printf("잘못된 물품코드를 입력하였습니다.\n");
      i--;
    } else {
      printf("물품코드: %d, 팔린 갯수: %5d, 물품 총 판매 금액: %8d원\n", code, num, price);
      total += price;
    }
  }

  printf("오늘의 정산 금액: %d원\n", total);
}
