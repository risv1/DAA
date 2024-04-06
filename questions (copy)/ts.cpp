#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int tsp(vector<vector<int>>& graph, int start, int bitmask, vector<vector<int>>& dp) {
    int n = graph.size();
    
    if (bitmask == (1 << n) - 1) // All cities have been visited
        return graph[start][0];   // Return to starting city
    
    if (dp[start][bitmask] != -1)
        return dp[start][bitmask];
    
    int minCost = INF;
    
    for (int city = 0; city < n; ++city) {
        if (!(bitmask & (1 << city))) { // If city not visited
            int newCost = graph[start][city] + tsp(graph, city, bitmask | (1 << city), dp);
            minCost = min(minCost, newCost);
        }
    }
    
    return dp[start][bitmask] = minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    cout << "Enter the cost matrix for the cities:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    int minCost = tsp(graph, 0, 1, dp); // Start from city 0 with bitmask representing the starting city
    cout << "Minimum cost to visit all cities: " << minCost << endl;

    return 0;
}
