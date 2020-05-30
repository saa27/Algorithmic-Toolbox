#include <iostream>

int get_fibonacci_last_digit_fast(int n)
{
    int a[n + 2];
    int i;
    a[0] = 0;
    a[1] = 1;
    int sum =0;
    for (i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1]) % 10 + (a[i - 2]) % 10;
    }
    for(i=0;i<=n;i++){
        sum += a[i] ;
    }

    std::cout <<sum<< '\n';
    return (a[n] % 10);
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
