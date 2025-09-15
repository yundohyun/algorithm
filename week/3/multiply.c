#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// START 
//   mult = 1, multified = 0 
//   read(n) 
//   for i = 1 to n do 
//     read(data) 
//     if (data != 0) then 
//       multified = 1 
//       mult = mult * data 
//     endif 
//   endfor 
//   if (multified == 0) then mult = 0 
//   print(mult) 
// END 

int main() {
  int mult = 1, n, data, multified = 0;
  printf("Input Integer Length: ");
  scanf("%d", &n);
  printf("Input %d Integers\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &data);
    if (data != 0) {
      multified = 1;
      mult *= data;
    }
  }
  if (multified == 0) mult = 0;
  printf("Multiflied Integer: %d\n", mult);
}