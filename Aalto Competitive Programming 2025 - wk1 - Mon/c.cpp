/*
Maija is a freshly graduated infrastructure architect and has now been given her first job by the local government: to fix the traffic problems at junction 1337.
Before she can start planning any solutions, she needs to understand the nature of the problem. To do this, she starts to analyze the weekly traffic data.
From the records, she extracts the following information for n anonymous cars numbered 1, 2, \dots, n: Car number i enters the junction at some time during the interval [l_i, r_i]. Now, she is going to calculate the maximum possible number of cars trying to enter the junction all at once.
Input
The first line contains an integer n, which is the number of cars.
Each of the next n lines contains two integers, l_i and r_i.
Output
Output the maximum number of cars trying to enter the junction all at once.
Constraints

1 \leq n \leq 10^5
1 \leq l_i \leq r_i \leq 60 \times 60 \times 24 \times 7 = 604800

Example 1
Input:
3
1 4
4 5
4 6

Output:
3

Explanation: all three cars might arrive at the intersection at second 4.
Example 2
Input:
4
1 2
3 5
4 6
7 8

Output:
2

Explanation: both cars 2 and 3 might arrive at the intersection at seconds 4 or 5.
Example 3
Input:
3
1 604800
54332 421232
32323 44444

Output:
2
------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    int f[604801];
    cin >> n;
    for (int i = 1; i <= 604800; i++) f[i] = 0;
    vector<int> a;
    vector<int> b;
    
    while (n > 0) {
        n--;
        int l, r;
        cin >> l >> r;
        a.push_back(l);
        b.push_back(r);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int res = 0;
    int ans = 0;
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= 604800; i++) {
        while (a[p1] == i) {
            ans++;
            p1++;
            if (p1 >= a.size()) break;
        } 
        if (ans > res) res = ans;
        while (b[p2] == i) {
            p2++;
            ans--;
            if (p2 >= b.size()) break;
        }
    }
        
        
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}