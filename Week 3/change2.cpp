#include <iostream>

int get_change(int m)
{

    int n = 0;
    for (int i = 0; i < m; i++)
    {
        if (m == 0)
            return n;
        while (m >= 10)
        {
            m = m - 10;
            n = n + 1;
        }
        while (m < 10 && m >= 5)
        {
            m = m - 5;
            n = n + 1;
        }
        while (m < 5 && m >= 1)
        {
            m = m - 1;
            n = n + 1;
        }
    }
    return n;
}

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
