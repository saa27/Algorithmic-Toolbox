#include <iostream>

long long pisano(long long m)
{
    int a = 0, b = 1,c=1;
    for (long long i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long remainder = n % pisano(m);
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long result = remainder;

    for (long long i = 1; i < remainder; ++i)
    {
        result = (previous + current) % m;
        previous = current;
        current = result;
    }

    return result % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
