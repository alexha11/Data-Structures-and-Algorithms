#include <bits/stdc++.h>
using namespace std;
 
# define MAXSUM 1000001 
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN1 = 1e5 + 1;
const int MAXN2 = 1e5;
 
ll n, q; 
ll a[MAXN1];
vector<ll> f(MAXN2, 0);
bitset<MAXSUM> bit;
 
void solve() {
   cin >> n >> q; 
   
   for (int i = 1; i <= n; i++) {
       cin >> a[i]; 
   }
    
    bit.reset(); 
 
    bit[0] = 1; 
    for (int i = 1; i <= n; i++) bit |= (bit << a[i]);
    
    for (int i = 1; i <= q; i++) { 
        int temp;
        cin >> temp;
 
        bit[temp]? cout << "Yes " : cout << "No "; 
    } 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}

// Time limit: 1.00 s
// Memory limit: 512 MB

// Working at the kindergarten, Maija is building a mock city from rocks with the kids. She has gotten more fired up about the thing than most of the children and is now building a full replica of New York's skyline. Maija has gathered n rocks numbered 1,2,\dots,n and the height of the i-th rock is a_i. She is going to build q towers numbered 1,2,\dots,q. The height of the i-th tower will be b_i. For each tower, determine if she can build it by towering the rocks she has currently at her disposal.
// Input
// The first line contains two integers n and q. The second line contains n integers a_1,\,a_2,\dots,\,a_n. The third line contains q integers b_1,\,b_2,\dots,\,b_q.
// Output
// Print the answers to the queries on a single line. Print "Yes" if it is possible to construct the tower and "No" otherwise.
// ans_1\ ans_2\ \dots\ ans_q
// Constraints

// 1 \leq n \leq 2000
// 1 \leq q \leq 10^5
// 1 \leq a_i \leq 10^5
// 1 \leq b_i \leq 10^6

// Example 1
// Input:
// 5 5
// 10 4 3 9 1 
// 5 38 11 99 60

// Output:
// Yes No Yes No No
// Example 2
// Input:
// 10 10
// 10 6 2 10 9 8 7 7 6 3 
// 15 98 23 1 70 26 91 44 64 78

// Output:
// Yes No Yes No No Yes No Yes No No