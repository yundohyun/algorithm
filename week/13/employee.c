#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  long eid;
  char name[20];
  int escore;
  char dname[5];
} employee;

void quick_eid_asc(employee a[], int left, int right) {
  if (left < right) {
    int i = left, j = right + 1;
    long pivot = a[left].eid;
    while (i < j) {
      do i++; while (i <= right && a[i].eid < pivot);
      do j--; while (j >= left && a[j].eid > pivot);
      if (i < j) {
        employee tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
    employee tmp = a[j];
    a[j] = a[left];
    a[left] = tmp;
    quick_eid_asc(a, left, j - 1);
    quick_eid_asc(a, j + 1, right);
  }
}

void quick_escore_desc(employee a[], int left, int right) {
  if (left < right) {
    int i = left, j = right + 1;
    int pivot = a[left].escore;
    while (i < j) {
      do i++; while (i <= right && a[i].escore > pivot);
      do j--; while (j >= left && a[j].escore < pivot);
      if (i < j) {
        employee tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
    employee tmp = a[j];
    a[j] = a[left];
    a[left] = tmp;
    quick_escore_desc(a, left, j - 1);
    quick_escore_desc(a, j + 1, right);
  }
}

int main(int argc, char *argv[]) {
  employee e[100];
  FILE *in, *out;
  char choice;
  int n = 0;

  if (argc < 3) {
    printf("잘못된 인수 갯수\n");
    exit(1);
  }

  if ((in = fopen(argv[1], "r")) == NULL) {
    printf("입력 파일을 열 수 없습니다.\n");
    exit(1);
  }

  if ((out = fopen(argv[2], "w")) == NULL) {
    printf("출력 파일을 열 수 없습니다.\n");
    exit(1);
  }

  while (fscanf(in, "%ld %s %d %s", &e[n].eid, e[n].name, &e[n].escore, e[n].dname) != EOF) n++;

  quick_eid_asc(e, 0, n - 1);

  for (int i = 0; i < n; i++)
    fprintf(out, "%ld\t%s\t%d\t%s\n", e[i].eid, e[i].name, e[i].escore, e[i].dname);

  quick_escore_desc(e, 0, n - 1);

  char dcode[5];
  printf("출력할 부서 코드를 입력하세요: ");
  scanf("%s", dcode);

  printf("-------- %s 부서 직원 목록 --------\n", dcode);

  int found = 0;
  for (int i = 0; i < n; i++) {
    if (strcmp(e[i].dname, dcode) == 0) {
      printf("%ld\t%s\t%d\t%s\n",
        e[i].eid, e[i].name, e[i].escore, e[i].dname);
      found = 1;
    }
  }
  if (!found) printf("해당 부서의 직원이 없습니다.\n");
  printf("------------------------\n");

  printf("-------- 영어성적 내림차순 정렬 출력 --------\n");
  for (int i = 0; i < n; i++)
    printf("%ld\t%s\t%d\t%s\n", e[i].eid, e[i].name, e[i].escore, e[i].dname);
  printf("------------------------\n");

  fclose(in);
  fclose(out);
  return 0;
}
