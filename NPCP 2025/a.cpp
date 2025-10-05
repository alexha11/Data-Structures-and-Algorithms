#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int s; 

  cin >> s;

  if (s == -999) {
    cout << -1 << ' ' << -998 << '\n';
    return 0;
  }

  if (s == 1) {
    cout << 2 << ' ' << -1 << '\n';
    return 0;
  }
  
  cout << 1 << ' ' << s - 1 << '\n'; 

  return 0;
}
