#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  int m = a.size();
  int n = b.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1));

  for(int i=0; i<=m ;i++){
    for(int j=0; j<=n ;j++){
      if(i==0)
        dp[i][j] = 0;
      else if(j==0)
        dp[i][j] = 0;
      else if(a[i-1]==b[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else 
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[m][n];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
