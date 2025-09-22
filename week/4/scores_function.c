#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double find_avg(int scores[][2], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += scores[i][1];
  return (double) sum / n;
}

int find_max(int scores[][2], int n) {
  int max = 0;
  for (int i = 0; i < n; i++)
    if (scores[i][1] > max)
      max = scores[i][1];
  return max;
}

int find_rank(int scores[][2], int n, int sid) {
  int rank = 1, jumsu;
  for (int i = 0; i < n; i++)
    if (scores[i][0] == sid) {
      jumsu = scores[i][1];
      break;
    }
  for (int i = 0; i < n; i++)
    if (scores[i][1] > jumsu) rank++;
  return rank;
}

int main() {
  int n, sid, jumsu = 0, rank = 1;
  printf("Input Student Length: ");
  scanf("%d", &n);
  int scores[n][2];
  for (int i = 0; i < n; i++) {
    printf("Input Student %d's ID and Score: ", i + 1);
    scanf("%d %d", &scores[i][0], &scores[i][1]);
  }
  printf("Input Student ID: ");
  scanf("%d", &sid);
  printf("Avg Score: %.2lf\n", find_avg(scores, n));
  printf("Max Score: %d\n", find_max(scores, n));
  printf("Student %d's Rank: %d\n", sid, find_rank(scores, n, sid));
}