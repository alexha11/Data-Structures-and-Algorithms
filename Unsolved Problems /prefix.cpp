// This is a range frequency query problem.
// We need to efficiently answer queries of the form:

// "How many people between indices [l, r] are interested in thing x?"

// 🔑 Key Insight

// For each "thing" x, we can store all indices where it appears.

// Then, for a query (l, r, x), we just need to count how many of those indices fall in [l, r].

// This can be done with binary search (lower_bound and upper_bound).

// This gives us:

// Preprocessing: O(n) to build index lists.

// Each query: O(log n).

// Total: O(n + q log n), which works for constraints up to 10^5.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n + 1);
    vector<vector<int>> positions(k + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        positions[a[i]].push_back(i); // store positions of each "thing"
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;

        const auto &vec = positions[x];
        // find count of indices in [l, r]
        int left = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        int right = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        cout << (right - left) << "\n";
    }

    return 0;
}
