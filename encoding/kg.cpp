#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
};

bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main() {
    int W;
    cout << "Enter the weight limit: ";
    cin >> W;

    int N;
    cout << "Enter the number of items: ";
    cin >> N;

    Item arr[N];
    for(int i = 0; i < N; i++) {
        cout << "Enter value and weight for item " << i+1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << "Maximum value in knapsack = " << fractionalKnapsack(W, arr, N);
    return 0;
}

// int main(){
//     double ratio[50], profit[50], weight[50], capacity, TotalValue;
//     int n,i,j;
//     cin >> n;
//     for(i=0; i<n; i++){
//         cin >> weight[i] >> profit[i];
//     }
//     cin >> capacity;
//     for(i=0; i<n; i++){
//         ratio[i] = profit[i]/weight[i];
//     }
//     for(i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(ratio[j] > ratio[i]){
//                 swap(ratio[i], ratio[j]);
//                 swap(profit[i], profit[j]);
//                 swap(weight[i], weight[j]);  
//             }
//         }
//     }
//     while(capacity>0){
//         if(weight[i] > capacity) break;
//         else{
//             TotalValue += profit[i];
//             capacity -= weight[i];
//         }
//     }
// }