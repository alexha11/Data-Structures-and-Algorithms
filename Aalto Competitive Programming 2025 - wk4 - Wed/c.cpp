#include <bits/stdc++.h>
using namespace std;

long long merge_count(vector<long long>& arr, int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (l + r) / 2;
    long long inv = merge_count(arr, l, mid) + merge_count(arr, mid, r);
    
    vector<long long> tmp;
    int i = l, j = mid;
    while (i < mid && j < r) {
        if (arr[i] <= arr[j]) {
            tmp.push_back(arr[i++]);
        } else {
            tmp.push_back(arr[j++]);
            inv += mid - i; 
        }
    }
    while (i < mid) tmp.push_back(arr[i++]);
    while (j < r) tmp.push_back(arr[j++]);
    for (int k = l; k < r; k++) arr[k] = tmp[k - l];
    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << merge_count(a, 0, n) << "\n";
    return 0;
}
