#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int q;
    cin >> n >> q;

    while (q--) {
        long long a, b;
        cin >> a >> b;

        long long g = std::gcd(n, a);
        cout << (n / g) << endl;
    }

    return 0;
}
