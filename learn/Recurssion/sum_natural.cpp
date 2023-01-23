#include <bits/stdc++.h>
using namespace std;

int sum(int n, int k = 0)
{
    if (n == 0)
    {
        return k;
    }
    return sum(n - 1, k + n);
}

int main()
{
    cout << sum(5);

    return 0;
}