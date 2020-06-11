#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int get_change(int money, int n, int coins[])
{
  vector<int> minNoCoins(money + 1, INT_MAX);
  minNoCoins[0] = 0;
  int result;

  for (int m = 1; m <= money; m++){
    for (int i = 0; i < n; i++){
      if (m >= coins[i]){
        result = minNoCoins[m - coins[i]] + 1;
        if (result < minNoCoins[m])
          minNoCoins[m] = result; 
      }
    }
  }
  return minNoCoins[money];
}

int main()
{
  int m;
  std::cin >> m;
  int coins[3] = {1, 3, 4};
  std::cout << get_change(m, 3, coins) << '\n';
}
