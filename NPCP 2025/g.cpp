#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

void dfs(int s, int cur_cc, vector<int> &cc, vector<vector<int>> &g, vector<vector<int>> &v_cc) {
  //cout << "HEllo" << endl;
  if(cc[s]!=-1) return;
  cc[s] = cur_cc;
  v_cc[cur_cc].push_back(s);
  for(auto u: g[s]){
    dfs(u, cur_cc, cc, g, v_cc);
  }
}

int main() {
  int n, m, k; 

  cin >> n >> m >> k;

  vector<vector<int>> g(n+1);

  vector<int> cc(n+1, -1);

  vector<vector<int>> v_cc;

  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> a;

  int curr_cc = 0;
  for(int i = 1; i<= n; i++){
    if(cc[i]==-1) {
      v_cc.push_back(a);
      dfs(i, curr_cc, cc, g, v_cc);
      curr_cc+=1;
    }
  }

  // for(int i = 1; i<= n; i++){
  //   cout << cc[i] << ' ';
  // }
  // cout << endl;

  bool possible = true;
  for(int i = 0; i< v_cc.size(); i++){
    // cout << i << endl;
    if(v_cc[i].size()<k) {
      possible = false;
      // cout << "impossible: " << i << endl;
    }
  }

  // for(int i = 0; i< v_cc.size(); i++){
  //   for(int j = 0; j< v_cc[i].size(); j++){
  //     cout << j << ':' << v_cc[i][j] << endl;
  //   }
  // }

  if (!possible) {
    cout << "impossible\n";
  } else {
    vector<int> answ(n+1);

    for(int i = 0; i< v_cc.size(); i++){
      for(int j = 0; j< v_cc[i].size(); j++){
        answ[v_cc[i][j]] = j%k + 1;
      }
    }
    for(int i = 1; i<= n; i++) {
      cout << answ[i] << ' ';
    }
    cout << endl;
  }

  




  return 0;
}

