/*
Teemu is going backpacking. His mom has given him two types of fruit: apples and bananas. As Teemu's stomach does not distinguish between them, each apple or banana gives him one hour of energy for backpacking. Given that his mom has given him A apples and B bananas, calculate how many hours Teemu can backpack if he has no other source of energy.
Input
The first line of input consists of two space-separated numbers, A and B.
Output
Output a single integer O: the number of hours before Teemu runs out of energy.
Constraints

0 \le A,B \le 10^6

Example
Input:
3 5

Output:
8
------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << a + b;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}