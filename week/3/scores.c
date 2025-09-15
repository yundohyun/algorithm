#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START
//   read(n)
//   for i = 0 to n do
//     read(scores(i, 0), scores(i, 1))
//   endfor
//   read(sid)
//   jumsu = 0
//   rank = 1
//   for i = 0 to n do
//     if (sid == scores(i, 0)) then
//       jumsu = scores(i, 1)
//     endif
//   endfor
//   for i = 0 to n do
//     if (score(i, 1) > jumsu) then rank = rank + 1
//   endfor
//   print(jumsu)
//   print(rank)
//   highestScore = 0, lowestScore = 100
//   for i = 0 to n do
//     if (score(i, 1) > highestScore) then
//       highestSid = score(i, 0)
//       highestScore = score(i, 1)
//     endif
//     if (score(i, 1) < lowestScore) then
//       lowestSid = score(i, 0)
//       lowestScore = score(i, 1)
//     endif
//   endfor
//   print(highestSid, highestScore)
//   print(lowestSid, lowestScore)
// END

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
  for (int i = 0; i < n; i++)
    if (scores[i][0] == sid) {
      jumsu = scores[i][1];
      break;
    }
  for (int i = 0; i < n; i++)
    if (scores[i][1] > jumsu) rank++;
  printf("Student %d's Score: %d\n", sid, jumsu);
  printf("Student %d's Rank: %d\n", sid, rank);

  int highestSid, lowestSid, highestScore = 0, lowestScore = 100;
  for (int i = 0; i < n; i++) {
    if (scores[i][1] > highestScore) {
      highestSid = scores[i][0];
      highestScore = scores[i][1];
    }
    if (scores[i][1] < lowestScore) {
      lowestSid = scores[i][0];
      lowestScore = scores[i][1];
    }
  }
  printf("Highest Score and Student ID: %d, %d Score\n", highestSid, highestScore);
  printf("Lowest Score and Student ID: %d, %d Score\n", lowestSid, lowestScore);
}