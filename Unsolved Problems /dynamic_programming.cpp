// Problem in one sentence

// Label the circular sequence of values 
// 𝐶
// 1
// …
// 𝐶
// 𝑁
// C
// 1
// 	​

// …C
// N
// 	​

//  with colors from {black (+), green (0), red (−)} so that adjacent colors differ (and also 
// 𝐶
// 𝑁
// C
// N
// 	​

//  adjacent to 
// 𝐶
// 1
// C
// 1
// 	​

// ), maximizing total 
// ∑
// 𝑠
// 𝑖
// 𝐶
// 𝑖
// ∑s
// i
// 	​

// C
// i
// 	​

//  where 
// 𝑠
// 𝑖
// ∈
// {
// +
// 1
// ,
// 0
// ,
// −
// 1
// }
// s
// i
// 	​

// ∈{+1,0,−1} according to the color.

// Key idea (DP on a cycle)

// Treat each color as an index 0..2 with values:

// color 0 = red → contribution 
// −
// 𝐶
// 𝑖
// −C
// i
// 	​


// color 1 = green → contribution 
// 0
// 0

// color 2 = black → contribution 
// +
// 𝐶
// 𝑖
// +C
// i
// 	​


// We need a circular constraint: adjacent indices must differ, and position 
// 𝑁
// N must differ from position 
// 1
// 1.

// Standard trick for cycles: fix the color of position 1 (try all 3 possibilities). For a fixed color start, run DP along positions 2..N on a path with adjacency constraint "current color != previous color". At the end only accept final colors that are different from start. Take the best among the three start choices.

// DP for fixed start:

// dp[pos][c] = best total up to pos if pos is colored c.

// initialize dp[1][start] = val(1,start), other colors = -inf.

// iterate pos = 2..N: dp[pos][c] = val(pos,c) + max_{p != c} dp[pos-1][p].

// final answer for this start: max_{c != start} dp[N][c].

// Complexity: try 3 starts × O(N × 3 × 1) transitions = O(N). Use long long.

// Proof sketch of correctness

// Fixing color 1 partitions the cyclic constraint: the rest become a path with forbidden equal adjacent colors and the final color must differ from the fixed start. Trying all 3 start colors covers all valid circular colorings. DP for a path with adjacency constraint is optimal because at each position the best depends only on previous position's choice.

// C++ implementation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = LLONG_MIN / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    vector<ll> C(N+1);
    for (int i = 1; i <= N; ++i) cin >> C[i];

    // color 0 = red (-C), 1 = green (0), 2 = black (+C)
    auto val = [&](int pos, int color) -> ll {
        if (color == 0) return -C[pos];
        if (color == 1) return 0;
        return C[pos];
    };

    ll answer = NEG;
    for (int start = 0; start < 3; ++start) {
        // dp for previous position
        array<ll,3> prev = {NEG, NEG, NEG};
        prev[start] = val(1, start);

        for (int pos = 2; pos <= N; ++pos) {
            array<ll,3> cur = {NEG, NEG, NEG};
            for (int c = 0; c < 3; ++c) {
                // choose previous color p != c
                ll bestPrev = NEG;
                for (int p = 0; p < 3; ++p) if (p != c) bestPrev = max(bestPrev, prev[p]);
                if (bestPrev > NEG/2) cur[c] = bestPrev + val(pos, c);
            }
            prev = cur;
        }

        // final color must differ from start
        for (int endc = 0; endc < 3; ++endc) {
            if (endc == start) continue;
            answer = max(answer, prev[endc]);
        }
    }

    cout << answer << '\n';
    return 0;
}
