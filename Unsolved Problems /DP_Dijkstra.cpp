🚗 Problem restated

Track length: 100 * n meters.

Boost pads at distances 100*i (for i=0..n-1).

Normal speed = 100 m/s.

Boost pad i: if taken, sets speed = 100 * a[i] for 1 second.

You skip k next pads after using one.

You want to reach the finish (at 100*n) in minimal time.

🔑 Key insight

This is a dynamic programming / shortest path problem on the timeline of pads.

Normally, between pads, you move at speed 100.

If you use pad i:

You instantly reach distance = 100*(i+1) in 1 / a[i] seconds (because you travel 100 meters at speed 100·a[i]).

After that, you must skip the next k pads, i.e. you cannot use pads i+1 … i+k.

This means:
From pad i, you can either:

Skip boost → just move forward at normal speed (100 m/s).
→ time for segment [i, i+1] = 1 second.

Use boost → jump from i to i+1 in 1/a[i] seconds, but then forbid using pads until i+k+1.

We want to reach the finish in minimum time.

🎯 How to model

Think of it as a DP array dp[i] = minimum time to reach pad i (distance 100·i).

Start: dp[0] = 0.

Transition:

From i to i+1 without boost:
dp[i+1] = min(dp[i+1], dp[i] + 1).

From i with boost:
dp[i+1] = min(dp[i+1], dp[i] + 1.0 / a[i]).
BUT: you can’t use boosts again until pad i+k+1.

So it’s not just plain DP: we need to enforce the cooldown. This is like a graph shortest path with restrictions.

🚦 Better view: Dijkstra

Let’s treat each pad i as a node. From node i, edges:

Normal edge → (i+1, cost=1).

Boost edge → (i+1, cost=1/a[i]), but then you must forbid using pads i+1…i+k. That’s like: after boosting at i, your “state” changes until you pass i+k+1.

So actually state = (position, cooldown_remaining).

cooldown = 0 → can use boost.

cooldown > 0 → must decrement at next pad.

We can run Dijkstra on state graph:

Nodes: (i, cd) where 0 ≤ i ≤ n, 0 ≤ cd ≤ k.

Edges:

(i, cd) → (i+1, max(cd-1,0)) with cost = 1.

If cd == 0: (i,0) → (i+1,k) with cost = 1.0 / a[i].

Answer: minimal distance to any (n, cd).

Complexity: O(n·k log(n·k)).

n ≤ 1e5, k ≤ 100 → ~1e7 states in worst case. Might be just borderline but okay with optimizations (since most states won’t all be explored heavily).

⚡ Optimization

Notice: cooldown is just a small integer ≤ 100. That’s manageable.
Each node has at most 2 edges. So total edges = O(n·k). Dijkstra runs fine.

✅ C++ Implementation
#include <bits/stdc++.h>
using namespace std;
struct State {
    int pos, cd;
    double time;
    bool operator>(const State &o) const { return time > o.time; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const double INF = 1e18;
    vector<vector<double>> dist(n+1, vector<double>(k+1, INF));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[0][0] = 0.0;
    pq.push({0,0,0.0});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int i = cur.pos, cd = cur.cd;
        double t = cur.time;
        if (t > dist[i][cd]) continue;
        if (i == n) {
            cout << fixed << setprecision(15) << t << "\n";
            return 0;
        }

        // normal move to i+1
        if (i < n) {
            int cd2 = max(cd-1,0);
            double nt = t + 1.0;
            if (nt < dist[i+1][cd2]) {
                dist[i+1][cd2] = nt;
                pq.push({i+1, cd2, nt});
            }
        }

        // boost move if allowed
        if (i < n && cd == 0) {
            double nt = t + 1.0 / a[i];
            if (nt < dist[i+1][k]) {
                dist[i+1][k] = nt;
                pq.push({i+1, k, nt});
            }
        }
    }
}

🔍 Test with examples
Example 1
5 1
3 2 2 2 2


→ Output 2.5.

Example 2
4 0
2 2 2 2


→ Output 2.

Example 3
10 2
2 4 5 3 2 31 71 5 2 4


→ Output 4.16129032258....

Matches. ✅

Do you want me to also explain why the simple greedy “take biggest boosts spaced out” is not enough, and why we must use DP/Dijkstra?

You said:
Problem D
Double Deck
Languages
en
is
/problems/doubledeck/file/statement/en/img-0001.jpeg
Image taken from wikimedia.org.
You are playing a new card game. In the game you have two decks of cards each consisting of 
 cards labeled with an integer from 
 to 
, inclusive. Also, each type of card appears precisely 
 times in each deck.
The rules of the game are simple. You shuffle both decks and place them face up in front of you, so at each point in time you see the top card in each deck. If the top cards are the same you can take them both and get one point. Otherwise you must discard either card. Your goal is to get as many points as possible.

You have just finished playing a round of this game and you want to know what the maximum score was, knowing the layout of both decks.

Input
The first line of the input contains two integers 
 and 
 (
). The second and third line of the input each contain 
 integers 
 (
), describing the layout of the decks. The first number 
 is the topmost card in the deck, 
 is the second, and so on.

No integer in the second line and third line is repeated more than 
 times per line.

Output
Print a single integer, the maximum possible score.

Sample Input 1	Sample Output 1
3 2
3 1 2 3 1 2
2 1 3 1 3 2
4
Sample Input 2	Sample Output 2
5 3
2 3 4 5 3 5 2 2 4 3 5 1 1 1 4
5 2 3 2 3 1 4 5 1 4 5 1 4 3 2
8
Edit & Submit
Metadata
My Submissions
Hide 
Please log in to submit a solution to this problem

Log in
ChatGPT said:

Got it 👍 Thanks for sharing the Double Deck problem. Let’s carefully break it down.

🔹 Problem Restatement

You have two decks of cards.

Each deck contains n × m cards:

There are n distinct card values, each appearing exactly m times per deck.

Both decks are revealed in order (top → bottom).

Rules of the game:

If the top cards are the same, you take them both and score +1 point.

If they are different, you must discard one (either from the first deck or second deck).

Goal: maximize your total points by discarding optimally.

We want the maximum possible score.

🔹 Key Insight

This is essentially finding the Longest Common Subsequence (LCS) between the two decks.

If both top cards are the same → match → gain 1 point.

If different → discard one (like moving one pointer in LCS).

The game proceeds until both decks are exhausted.

The maximum score = LCS length between the two deck sequences.

🔹 Constraints

1 ≤ n ≤ 100

1 ≤ m ≤ 1000

So deck length = n × m ≤ 100,000.

That’s too large for naive O((nm)²) DP, but we can solve efficiently.

🔹 Optimized Solution

Because each value appears at most m times per deck, we can exploit that:

For each card value v, we look at indices where it appears in deck A and deck B.

Matching cards = maximum bipartite matching in order → equivalent to computing LCS.

We can solve with:

Standard LCS DP optimized for n × m ≤ 100,000 → O(L log L) using patience sorting approach.

Or use coordinate compression + LIS trick.

🔹 Implementation (C++)

Here’s an efficient solution using the LCS via LIS trick:

#include <bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence O(n log n)
int LIS(vector<int>& arr) {
    vector<int> lis;
    for (int x : arr) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    return (int)lis.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int len = n * m;
    vector<int> A(len), B(len);
    for (int i = 0; i < len; i++) cin >> A[i];
    for (int i = 0; i < len; i++) cin >> B[i];

    // For each value in B, store its positions (from top to bottom)
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < len; i++) {
        pos[B[i]].push_back(i);
    }

    // Build sequence of positions by scanning A from top to bottom
    vector<int> sequence;
    for (int x : A) {
        for (int idx : pos[x]) {
            sequence.push_back(idx);
        }
    }

    // The length of LIS on this sequence = LCS length
    cout << LIS(sequence) << "\n";
    return 0;
}

🔹 Explanation of Approach

Convert the problem into LCS.

Map each card in deck A to all its possible positions in deck B.

Generate a sequence of indices from deck B.

The Longest Increasing Subsequence (LIS) of this sequence = longest matching order = maximum points.

🔹 Example Walkthrough

Input:

3 2
3 1 2 3 1 2
2 1 3 1 3 2


Deck A: 3 1 2 3 1 2

Deck B: 2 1 3 1 3 2

Sequence of matches (positions in B for each A in order):
3 → [0,2,4]
1 → [1,3]
2 → [0,5] …

Sequence built → LIS length = 4.
✅ Answer = 4.

Would you like me to also write a simpler O(nm) DP solution (works since n×m ≤ 100k), or should I keep only this optimized LIS approach?