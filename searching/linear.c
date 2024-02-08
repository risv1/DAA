#include <stdio.h>

int search(int array[], int n, int x) {
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
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

  int flag = search(list, n, x);

  if(flag!=-1){
    printf("Element found at index %d", flag);
  } else {
    printf("Element not found");
  }
}
