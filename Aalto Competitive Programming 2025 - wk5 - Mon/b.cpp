#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main(){
  int n;
  std::cin >> n;
  std::vector<std::string> cars(n);
  for (int i = 0; i<n; ++i){
    std::cin >> cars[i];
  }
 
  auto cmp = [](std::string& a, std::string& b){
    return a+b < b+a;
  };
  std::sort(cars.begin(), cars.end(), cmp);
 
  for (int i = 0; i<n; ++i){
    std::cout << cars[i];
  }
  std::cout << std::endl;
 
}