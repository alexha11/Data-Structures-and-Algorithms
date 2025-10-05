#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int increase_limit(int l){
  if(l%10 == 0) { return l + 10;}
  else return l + (10-l%10);
}

int main() {
  int n; 

  cin >> n;
  vector <string> v(n, "");

  for (int i=0; i<n; i++) {
    cin >> v[i];
  }
  
  cout << v[0] << endl;
  int max_lim_sofar = atoi(v[0].c_str());

  for (int i=1; i<n; i++) {
    if (v[i] == "/") {
      cout << increase_limit(max_lim_sofar) << endl;
    }
    else {
      cout << v[i] << endl;
      if (atoi(v[i].c_str())>max_lim_sofar) { 
        max_lim_sofar=atoi(v[i].c_str());
      }
    }
  }

  return 0;
}
