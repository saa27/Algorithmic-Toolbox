#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool GreaterOrEqual(string& a, string& b) {
	return(b + a > a + b);
}

string largest_number(vector<string> Nums) {
    int n = Nums.size();
	for (size_t i = 1; i < n; i++) {
		for (size_t j = 0; j < n - i; j++) {
			if (GreaterOrEqual(Nums[j], Nums[j + 1])) {
				swap(Nums[j], Nums[j + 1]); 
			}
		}
	}
	std::stringstream Salary; 
	for (size_t i = 0; i < n; i++) {
		Salary << Nums[i]; 
	}
	return Salary.str(); 
}


int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
