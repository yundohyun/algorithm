#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void selection_sort(int list[], int n) {
  for (int s = 0; s < n - 1; s++) {
    int m = s;
    for (int j = s + 1; j < n; j++) {
      if (list[j] < list[m]) m = j;
      int tmp = list[s];
      list[s] = list[m];
      list[m] = tmp;
    }
  }
}

int main() {
  
}