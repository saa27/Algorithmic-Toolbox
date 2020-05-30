#include <iostream>



int gcd_fast(int a, int b)
{
  int a1;
  if (b == 0)
  {
    return a;
  }
  else
  {
    a1 = a % b;
    a = b;
    b = a1;
    return gcd_fast(a, b);
  }
}
long long lcm_fast(int a, int b)
{
  return (long long)a * b / gcd_fast(a,b);
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl ;
  return 0;
}
