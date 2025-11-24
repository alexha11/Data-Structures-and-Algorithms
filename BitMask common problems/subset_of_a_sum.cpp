#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mid = n / 2;
    vector<long long> left(a.begin(), a.begin() + mid);
    vector<long long> right(a.begin() + mid, a.end());

    vector<long long> L, R;

    // generate subset sums for left
    int leftN = left.size();
    for (int mask = 0; mask < (1 << leftN); mask++) {
        long long sum = 0;
        for (int i = 0; i < leftN; i++)
            if (mask & (1 << i)) sum += left[i];
        L.push_back(sum);
    }

    // generate subset sums for right
    int rightN = right.size();
    for (int mask = 0; mask < (1 << rightN); mask++) {
        long long sum = 0;
        for (int i = 0; i < rightN; i++)
            if (mask & (1 << i)) sum += right[i];
        R.push_back(sum);
    }

    sort(R.begin(), R.end());

    long long ans = 0;

    // for each left-sum find how many right-sums = x - leftSum
    for (long long s : L) {
        long long target = x - s;
        auto lo = lower_bound(R.begin(), R.end(), target);
        auto hi = upper_bound(R.begin(), R.end(), target);
        ans += (hi - lo);
    }

    cout << ans << "\n";
}
