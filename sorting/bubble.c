#include <stdio.h>

void bubbleSort(int list[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &list[i]);
    }

    bubbleSort(list, n);

    printf("Sorted Array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", list[i]);
    }
    
    return 0;
}