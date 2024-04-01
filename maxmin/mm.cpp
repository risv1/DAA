#include <iostream>
using namespace std;

struct Pair {
    int max;
    int min;
};

Pair maxMinDivideConquer(int arr[], int low, int high) {
    Pair result, left, right;
    int mid;
    
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }


    mid = (low + high) / 2;
    left = maxMinDivideConquer(arr, low, mid);
    right = maxMinDivideConquer(arr, mid + 1, high);
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;
    return result;
}
int main() {
    int arr[] = {6, 4, 26, 14, 33, 64, 46};
    int n = sizeof(arr) / sizeof(arr[0]);
    Pair result = maxMinDivideConquer(arr, 0, n - 1);
    cout << "Maximum element is: " << result.max << endl;
    cout << "Minimum element is: " << result.min << endl;
    return 0;
}