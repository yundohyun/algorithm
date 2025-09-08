#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START
//   sum = 0
//   read(length)
//   for count = 1 to length do
//     read(data)
//     sum = sum + data
//   endfor
//   avg = sum / length
//   print(avg)
// END

int main() {
  int data, length, sum = 0, avg;
  printf("Input Integer length: ");
  scanf("%d", &length);
  printf("Input %d Integers\n", length);
  for (int count = 0; count < length; count++) {
    scanf("%d", &data);
    sum += data;
  }
  avg = sum / length;
  printf("Avg: %d\n", avg);
}