#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int get_change(int money, int n, int coins[])
{
  vector<int> minNoCoins(money + 1, INT_MAX); //size = 7
  minNoCoins[0] = 0;
  int result;

  for (int m = 1; m <= money; m++){ //m <=6 
    for (int i = 0; i < n; i++){ //i < 3
      if (m >= coins[i]){//1>=1, 2>=1
        result = minNoCoins[m - coins[i]] + 1;//result= 0, 
        if (result < minNoCoins[m])
          minNoCoins[m] = result; // 
      }
    }
  }
  return minNoCoins[money];
}

int main()
{
  int m;
  std::cin >> m; //6
  int coins[3] = {1, 3, 4};
  std::cout << get_change(m, 3, coins) << '\n';
}
