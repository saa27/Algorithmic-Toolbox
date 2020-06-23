#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

using namespace std;

int optimal_weight(int W, const vector<int> &wt, int capacity) {
  vector<vector<int>> matrix(capacity+1, vector<int>(W + 1));
  for(int i=0; i<=capacity; i++){
    for(int w=0; w<=W; w++){
      if(i==0 || w==0)
        matrix[i][w] = 0;
      else if(wt[i-1] <= w)
        matrix[i][w] = max(matrix[i-1][w], matrix[i-1][w-wt[i-1]] + wt[i-1]);
      else
        matrix[i][w] = matrix[i-1][w];
    }
  }
  //write your code here
 /*  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  } */
  return matrix[capacity][W];
}

int main() {
  int capacity, W;
  std::cin >> W >> capacity;
  vector<int> w(capacity);
  for (int i = 0; i < capacity; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w, capacity) << '\n';
}
