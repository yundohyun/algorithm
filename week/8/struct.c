#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct member {
  int id;
  char name[20];
  float score;
} member;

void over40(member *data, int n) {
  printf("List of high score students(over 4.0)\n");
  for (int i = 0; i < n; i++)
  if (data[i].score >= 4.0)
    printf("%d -- %s\n", data[i].id, data[i].name);
}

member find_max(member *data, int n) {
  int idx = 0;
  for (int i = 1; i < n; i++)
    if (data[i].score > data[idx].score) idx = i;
  return data[idx];
}

int main() {
  int n;
  printf("Input the number of data: ");
  scanf("%d", &n);
  member members[n];
  for (int i = 0; i < n; i++) {
    printf("데이터 입력: ");
    scanf("%d %s %f", &members[i].id, members[i].name, &members[i].score);
  }
  over40(members, n);
  member max = find_max(members, n);
  printf("Information of the highest score student = %d : %s : %.2f\n", max.id, max.name, max.score);
}