#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    long long X;
    cin >> n >> m >> X;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    // Step 1: Topological sort using Kahn’s algorithm
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    // If topological order doesn't contain all nodes => cycle
    if ((int)topo.size() != n) {
        cout << "No\n";
        return 0;
    }

    // Step 2: Compute reachability counts (number of reachable nodes)
    vector<long long> reach(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        int u = topo[i];
        for (int v : adj[u]) {
            reach[u] += (1 + reach[v]);
            if (reach[u] > X) { // early exit if limit exceeded
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}


// Got it 👍 — let’s solve the “Microservice Hell” problem step by step in C++.

// 🧠 Problem Understanding

// We are given:

// n nodes (services)

// m directed edges (a_i → b_i)

// a limit X

// Each directed edge means “service a_i calls service b_i”.
// We must check:

// For every node, if you start from it and recursively follow calls, the total number of reachable services must not exceed X.

// If any node can reach more than X nodes (including indirect calls), or if there is a cycle (which causes infinite recursion), output "No".
// Otherwise, output "Yes".

// 🧩 Step-by-Step Solution Plan

// Detect cycles:

// If a cycle exists → infinite calls → output "No".

// Compute total reachable nodes (like number of descendants in a DAG):

// After confirming the graph is acyclic, we can topologically sort it.

// Then for each node (in reverse topological order), compute:

// reach[u] = sum(reach[v] + 1) for all edges u → v


// If reach[u] > X for any node, output "No".

// If all nodes’ reach <= X → output "Yes".

// ⚙️ Complexity

// Building the graph: O(m)

// Cycle detection + Toposort: O(n + m)

// Propagation of reachable counts: O(n + m)
// ✅ Fits constraints easily.

// 🧾 Example Walkthrough

// Example 1:

// 5 6 8
// 5 3
// 3 4
// 3 2
// 3 1
// 4 1
// 2 1


// No cycles.

// Reachable counts per node:

// 5 → {3,4,2,1} = 4

// 3 → {4,2,1} = 3

// 4 → {1} = 1

// 2 → {1} = 1

// 1 → {} = 0
// → max = 4 ≤ 8 ✅ → Yes