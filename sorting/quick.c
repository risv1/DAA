#include <stdio.h>

void switchElement(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      i++;

      switchElement(&array[i], &array[j]);
    }
  }

  switchElement(&array[i + 1], &array[high]);

  return (i + 1);
}

void quick(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    quick(array, low, pi - 1);
    quick(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int list[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &list[i]);
  }

  int N = sizeof(list) / sizeof(list[0]);
  
  printf("Unsorted Array\n");
  printArray(list, n);

  quick(list, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(list, n);
}