#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	long id;
	char name[20];
	double score;
} student;

void sort_id_asc(student a[], int n) {
  student key;
  for (int i = 1; i < n; i++) {
    key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j].id > key.id) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

void sort_score_desc(student a[], int n) {
  student key;
  for (int i = 1; i < n; i++) {
    key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j].score < key.score) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

int main(int argc, char **argv) {
	student s[50];
	FILE *in, *out;
	char choice;
	
	if (argc < 3) {
		printf("올바르지 않은 인수 갯수\n");
		exit(1);
	}

	if ((in = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일 열 수 없음\n");
		exit(1);
	}

	if ((out = fopen(argv[2], "w")) == NULL) {
		printf("출력 파일 열 수 없음\n");
		exit(1);
	}

  int i = 0;
  while (fscanf(in, "%ld %s %lf", &s[i].id, s[i].name, &s[i].score) != EOF) i++;

  printf("-------- 정렬 전 학생 정보 --------\n");
  for (int j = 0; j < i; j++)
    printf("%ld\t%s\t%.2lf\n", s[j].id, s[j].name, s[j].score);
  printf("----------------------------------\n");

  printf("정렬 기준을 선택하세요 (1: 학번 오름차순, 2: 성적 내림차순): ");
  scanf("%c", &choice);

  if (choice == '1') sort_id_asc(s, i);
  else if (choice == '2') sort_score_desc(s, i);
  else {
    printf("잘못된 선택입니다.\n");
    fclose(in);
    fclose(out);
    exit(1);
  }

  for (int j = 0; j < i; j++)
    fprintf(out, "%ld\t%s\t%.2lf\n", s[j].id, s[j].name, s[j].score);

  printf("-------- 정렬 후 학생 정보 --------\n");
  for (int j = 0; j < i; j++)
    printf("%ld\t%s\t%.2lf\n", s[j].id, s[j].name, s[j].score);
  printf("----------------------------------\n");

  fclose(in);
  fclose(out);
}