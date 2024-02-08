#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int n, x;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int list[n];
  printf("Enter the elements: ");
  for(int i=0; i<n; i++){
    scanf("%d", &list[i]);
  }

  printf("Enter the element to be searched: ");
  scanf("%d", &x);

  int result = binarySearch(list, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
