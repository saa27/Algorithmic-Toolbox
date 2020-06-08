#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

int get_max_ratio_index(vector<int> weights,vector<int> values){
    int max_i =0;
    double max = 0.0;

    for(int i=0; i<weights.size(); i++){
        if(weights[i] != 0 && (double)values[i]/weights[i] > max){
            max = (double)values[i]/weights[i];
            max_i =i; //2, 0
        }
    }
    return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  
  for(int i=0; i<weights.size();i++){
      if(capacity == 0)
        return value;
      int index = get_max_ratio_index(weights,values);
      int a = capacity< weights[index] ? capacity: weights[index]; //30, capacity = 10
      value += a* (double)values[index]/weights[index]; //value = 0+ 30*(120/30) = 120 , value = 0 + 10* 500/30
      weights[index] -=a; // weights[2] = weights[2] - 30 = 0
      capacity -=a; // capacity = 20
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed;
  std::cout << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
