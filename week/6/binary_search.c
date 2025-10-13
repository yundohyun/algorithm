#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void selection_sort(int list[], int n) {
	int m, tmp;
	for (int i = 0; i < n - 1; i++) {
		m = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[m]) m = j;
		tmp = list[i];
		list[i] = list[m];
		list[m] = tmp;
	}
}

void selection_sort_desc(int list[], int n) {
	int m, tmp;
	for (int i = 0; i < n - 1; i++) {
		m = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] > list[m]) m = j;
		tmp = list[i];
		list[i] = list[m];
		list[m] = tmp;
	}
}

int binary_search(int list[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (list[mid] == key) return mid; 
    else if (list[mid] > key) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
}

int binary_search_desc(int list[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (list[mid] == key) return mid; 
    else if (list[mid] < key) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
}

int main() {
  int n, key, desc, sorted;
  printf("Input Integer Length: ");
  scanf("%d", &n);
  int data[n];

  printf("Input %d Integers\n", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &data[i]);

  printf("Input Key Integer: ");
  scanf("%d", &key);

  printf("Input 0 or 1 (ASC = 0, DESC = 1): ");
  scanf("%d", &desc);

  printf("Integer is Sorted? (0 or 1): ");
  scanf("%d", &sorted);
  if (sorted != -1) {
    if (desc == 1)
      selection_sort_desc(data, n);
    else
      selection_sort(data, n);
    printf("Sorted Integers:\n");
    for (int i = 0; i < n; i++)
      printf("%d ", data[i]);
    printf("\n");
  }

  int idx = desc == 1 ?
    binary_search_desc(data, n, key) :
    binary_search(data, n, key);
    
  if (idx != -1)
    printf("Key Index: %d\n", idx);
  else
    printf("Key is not exist.\n");
}