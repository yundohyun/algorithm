#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START
//   read(n1, n2, n3)
//   large = 0
//   if (n1 > large) then large = n1
//   if (n2 > large) then large = n2
//   if (n3 > large) then large = n3
//   print(large)
// END

int main() {
  int n1, n2, n3;
  int large = 0;
  printf("Input 3 Integers: ");
  scanf("%d %d %d", &n1, &n2, &n3);
  if (n1 > large) large = n1;
  if (n2 > large) large = n2;
  if (n3 > large) large = n3;
  printf("Largest: %d\n", large);
}