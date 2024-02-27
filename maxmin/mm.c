#include <stdio.h>

void max_min(int arr[], int l, int r, int *min, int *max) {
    if (r - l + 1 <= 2) {
        if (arr[l] <= arr[r]) {
            *min = arr[l];
            *max = arr[r];
        } else {
            *min = arr[r];
            *max = arr[l];
        }
        return;
    }

    int mid = (l + r) / 2;
    int left_min, left_max, right_min, right_max;

    max_min(arr, l, mid, &left_min, &left_max);
    max_min(arr, mid + 1, r, &right_min, &right_max);

    *min = (left_min < right_min) ? left_min : right_min;
    *max = (left_max > right_max) ? left_max : right_max;
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    max_min(arr, 0, size - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
