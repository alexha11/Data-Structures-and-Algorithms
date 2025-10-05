#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <unordered_set>
using namespace std;

long long n, m;
long long u, v;

int main() {
    cin >> n >> m;

    vector<unordered_set<int>> foll(n+1);

    for(int i = 0; i < m; i++) {
        cin >> u >> v;

        if (auto search = foll[u].find(v); search != foll[u].end()) {
            foll[u].erase(search);
        } else {
            foll[v].insert(u);
        }
    }

    int node =1;
    int cc = foll[1].size();

    for(int i = 2; i <= n; i++) {
        if (foll[i].size()>cc) {
            node = i;
            cc = foll[i].size();
        }
    }

    cout << node << ' ' << cc << endl;
}

