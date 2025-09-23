// Nice one — this is a classic sliding window / two pointers type problem 👩🏻‍🚀. Let’s unpack it step by step.

// 🚀 Problem Restatement

// We have an array of length n (a_1, a_2, …, a_n), where a_i = height of the moon surface at position i.

// We want to find the longest consecutive subarray (strip) such that:

// max
// ⁡
// (
// 𝑎
// 𝑙
// ,
// …
// ,
// 𝑎
// 𝑟
// )
// −
// min
// ⁡
// (
// 𝑎
// 𝑙
// ,
// …
// ,
// 𝑎
// 𝑟
// )
// ≤
// 𝑥
// max(a
// l
// 	​

// ,…,a
// r
// 	​

// )−min(a
// l
// 	​

// ,…,a
// r
// 	​

// )≤x

// Output:

// The starting index l (1-based), and

// The length (r - l + 1).

// If multiple longest strips exist, any one is fine.

// 🔑 Key Insight

// We need the longest subarray where max - min ≤ x.
// This screams sliding window with monotonic deques:

// Maintain a window [L, R] as we scan with R from 1 → n.

// Keep two deques:

// maxDeque → indices of elements in decreasing order (front = max).

// minDeque → indices of elements in increasing order (front = min).

// For each new R:

// Add a[R] into both deques (removing back elements to maintain order).

// While maxDeque.front() - minDeque.front() > x, shrink from the left (L++).

// Track the best (length, start) whenever the condition is satisfied.

// This ensures O(n) time because each element enters and leaves a deque at most once.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    deque<int> maxD, minD;
    int L = 1;
    int bestLen = 0, bestStart = 1;

    for (int R = 1; R <= n; R++) {
        // Maintain max deque (front = index of largest element)
        while (!maxD.empty() && a[maxD.back()] <= a[R]) 
            maxD.pop_back();
        maxD.push_back(R);

        // Maintain min deque (front = index of smallest element)
        while (!minD.empty() && a[minD.back()] >= a[R]) 
            minD.pop_back();
        minD.push_back(R);

        // Shrink from left until condition satisfied
        while (!maxD.empty() && !minD.empty() && (a[maxD.front()] - a[minD.front()] > x)) {
            if (maxD.front() == L) maxD.pop_front();
            if (minD.front() == L) minD.pop_front();
            L++;
        }

        // Update best strip
        int currLen = R - L + 1;
        if (currLen > bestLen) {
            bestLen = currLen;
            bestStart = L;
        }
    }

    cout << bestStart << " " << bestLen << "\n";
    return 0;
}
