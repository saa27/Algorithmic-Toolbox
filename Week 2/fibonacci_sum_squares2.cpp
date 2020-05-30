#include <iostream>

long long pisano(long long m)
{
    int a = 0, b = 1,c=1;
    for (long long i = 0; i < m*m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }
}

long long get_fibonacci_sum_last_digit(long long n)
{
    long long remainder = n % pisano(10);
    if (n <= 1)
        return n;
    if(remainder <=0){
        return 0;
    }
    else{
    long long previous = 0;
    long long current = 1;
    long long result = remainder;
    long long sum = 1;

    for (long long i = 1; i < remainder; ++i)
    {
        result = (previous + current) % 10;
        previous = current;
        current = result;
        sum +=result*result;
    }
    return sum % 10;
    }
}

int main()
{
    long long n;
    std::cin >> n ;
    std::cout << get_fibonacci_sum_last_digit(n) << '\n';
}
