#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START
//   over_count = 0
//   read(n)
//   for i = 0 to n do
//     read(scores(i))
//     sum = sum + scores(i)
//   endfor
//   sum = 0
//   avg = score / n
//   for i = 0 to n do
//     if (scores(i) > avg) then over_count = over_count + 1
//   endfor
//   print(avg)
//   print(over_count)
// END

int main() {
  int n, sum = 0, over_count = 0;
  printf("Input Integer Length: ");
  scanf("%d", &n);
  printf("Input %d Integers\n", n);
  int scores[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &scores[i]);
    sum += scores[i];
  }
  double avg = (double) sum / n;
  for (int i = 0; i < n; i++)
    if (scores[i] > avg) over_count++;
  printf("Integers Average: %.2lf\n", avg);
  printf("Integer Over Average Count: %d\n", over_count);
}