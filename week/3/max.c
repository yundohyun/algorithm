#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START
//   large = 0
//   read(n)
//   for i = 1 to n do
//     read(data)
//     if (data > large) then data = large
//   endfor
//   print(large)
// END

int main() {
  int large = 0, n, data;
  printf("Input Integer Length: ");
  scanf("%d", &n);
  printf("Input %d Integers\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &data);
    if (data > large) large = data;
  }
  printf("Largest Integer: %d\n", large);
}