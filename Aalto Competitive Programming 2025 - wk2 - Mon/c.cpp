#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<string> a;
pair<int, int> start, endd;
queue<pair<int, int>> q; 
int check[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

bool ok = false;

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') start = {i, j};
            if (a[i][j] == 'B') endd = {i, j};
        }
    }

    q.push(start);
    check[start.first][start.second] = 1;

    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveDir(n, vector<char>(m));

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        if (curr == endd) {
            ok = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int currx = curr.first + dx[i];
            int curry = curr.second + dy[i];
            if (currx >= 0 && currx < n && curry >= 0 && curry < m &&
                a[currx][curry] != '#' && !check[currx][curry]) {
                q.push({currx, curry});
                parent[currx][curry] = {curr.first, curr.second};
                moveDir[currx][curry] = dir[i];
                check[currx][curry] = 1;
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string path;
        pair<int,int> cur = endd;
        while (cur != start) {
            path += moveDir[cur.first][cur.second];
            cur = parent[cur.first][cur.second];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        cout << path << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
