#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sort_stock(int a[][2], int n) {
  int i = n - 1, flag = 1, tmp;
  while (flag && i != 0) {
    flag = 0;
    for (int j = 0; j <= i -1 ;j++) {
      if (a[j][0] > a[j + 1][0]) {
        flag = 1;
        for (int i = 0; i < 2; i++) {
          tmp = a[j][i];
          a[j][i] = a[j + 1][i];
          a[j + 1][i] = tmp;
        }
      }
    }
    i--;
  }
}

int search_stock(int a[][2], int n, int key) {
  int left = 0, right = n - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (key < a[mid][0]) right = mid - 1;
    else if (key > a[mid][0]) left = mid + 1;
    else return mid;
  }
  return -1;
}

int main(int argc, char **argv) {
  int num = 0, stock[100][2], input, result;
  FILE *file;
  
  if ((file = fopen(argv[1], "r")) == NULL) {
    printf("파일 읽기 오류\n");
    exit(1);
  }

  while (fscanf(file, "%d %d", &stock[num][0], &stock[num][1]) != EOF)
    num++;

  printf("저장된 물품코드\n");
  for (int i = 0; i < num; i++)
    printf("%d %d\n", stock[i][0], stock[i][1]);

  sort_stock(stock, num);

  printf("\n정렬된 물품코드\n");
  for (int i = 0; i < num; i++)
    printf("%d %d\n", stock[i][0], stock[i][1]);

  printf("\n검색할 아이템 코드 : ");
  scanf("%d", &input);
  result = search_stock(stock, num, input);
  if (result == -1)
    printf("재고가 없습니다.\n");
  else
    printf("%d의 재고 갯수 : %d\n", stock[result][0], stock[result][1]);
}
