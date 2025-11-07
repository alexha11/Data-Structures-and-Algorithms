#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int N = 1 << n; // total masks = 2^n
    vector<long long> dp(N, 1e18);
    dp[0] = 0; // base case: no workers assigned yet

    for (int mask = 0; mask < N; mask++) {
        int i = __builtin_popcount(mask); // worker index to assign next
        if (i >= n) continue;
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) { // if job j is free
                int new_mask = mask | (1 << j);
                dp[new_mask] = min(dp[new_mask], dp[mask] + cost[i][j]);
            }
        }
    }

    cout << dp[N - 1] << "\n"; // minimum total cost
}

// Given an n × n cost matrix, find the minimum cost to assign each of n workers to n jobs, where each worker does exactly one job and each job is done by exactly one worker.

// 🧩 Problem Statement — “Assignment Problem”