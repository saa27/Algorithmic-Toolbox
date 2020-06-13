  
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dynamic_sequence(int n) {
  vector<int> a(n+1);// a filled with 0
  vector<int> predecessor(n+1);// pre filled 0

  for (int i = 2; i <= n; i++) {//i=2;3;4;5
    a[i] = a[i-1] + 1;//a[2] = a[1] + 1 = 1; a[3]= 1+1 =2;a[4]=2;a[5]=3
    predecessor[i] = i - 1;//pre[2] = 1;pre[3]=2;pre[4]=3;pre[5]=4
    if (i % 3 == 0) {//no,yes
      if (a[i/3] < a[i]) {//if a[1]<a[3] i.e. 0<2
        a[i] = a[i/3] + 1;//a[3]=a[1]+1 =1;
        predecessor[i] = i/3;//pre[3]=1
      }
    }
    if (i % 2 == 0) {//yes;yes
      if (a[i/2] < a[i]) {//if a[1]<a[2] i.e. 0<1;if a[2]<a[4] i.e. 1<2
        a[i] = a[i/2] + 1;//a[2] = a[1] + 1 = 1;a[4]=2;
        predecessor[i] = i/2;//pre[2] = 1;pre[4]=2;       
      }
    }
  }
  //pre={0,0,1,1,2,4}//={0,0,1,1,2,4,3,6,4,3,9}
  /* for (size_t i = 0; i < predecessor.size(); ++i) {
    std::cout << predecessor[i] << " ";
  }

  std::cout <<std::endl; */

  vector<int> sequence;

  for (int i = n; i !=0; i = predecessor[i]) {//for(i=5;i!=0;i=4);i=10;9;3,1
    sequence.push_back(i);//5,4,2,1//10,9,3,1
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dynamic_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}