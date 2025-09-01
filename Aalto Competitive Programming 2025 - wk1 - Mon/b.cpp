/*
Uolevi and Maija are playing a game with two piles of stones. The players take turns, and on each turn a player may perform one of the following actions:

Take one or more stones from one pile and put them onto the other pile.
Take one or more stones from one pile and discard them.

The first player who cannot make a move loses. Determine the winner if both players play optimally and Uolevi goes first, or report that the game will continue indefinitely (i.e., it is a draw).
Input
The first line of input consists of two space-separated numbers, a and b: the numbers of stones in the two piles.
Output
Output "Uolevi", "Maija", or "Draw", indicating the result of the game. Note that the output is case-sensitive.
Constraints

1 \leq a, b \leq 300

Example 1
Input:
 1 2 

Output:
 Uolevi 
Example 2
Input:
 1 1 

Output:
 Maija 
Example 3
Input:
 239 123 

Output:
 Uolevi 
------------------------------------------------------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b; 
    if ((a == 1) & (b == 1) ) {
        cout << "Maija";
    } else cout << "Uolevi";
    
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}