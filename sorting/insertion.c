#include <stdio.h>

void insertionSort(int list[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &list[i]);
    }

    insertionSort(list, n);

    printf("Sorted Array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", list[i]);
    }
    
    return 0;
}