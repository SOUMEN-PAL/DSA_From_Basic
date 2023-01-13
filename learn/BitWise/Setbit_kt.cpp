#include <iostream>
using namespace std;

// naive solution //
void setbit(int n, int k)
{
    if (n == 0)
    {
        cout << "Not Set" << endl;
    }
    else
    {
        for (int i = 0; i < (k - 1); i++)
        {
            n = n / 2;
        }
        if ((n & 1) != 0)
        {
            cout << "Set" << endl;
        }
        else
        {
            cout << "Not Set" << endl;
        }
    }
}
void setbit_2(int n, int k)
{
    int x = 1;
    for (int i = 0; i < (k - 1); i++)
    {
        x = x * 2; // aka 2^(k-1) //
    }
    if ((n & x) != 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

// Efficient solution //
void eff_set_bit(int Num_M, int K_TH_BIT)
{
    if ((Num_M >> (K_TH_BIT - 1)) & 1 != 0)
    {
        cout << "Set" << endl;
    }
    else
    {
        cout << "Not set" << endl;
    }
}

void eff_set_bit2(int n, int k)
{
    int x = 1;
    if (n & (x << (k - 1)) != 0)
    {
        cout << "Yes Set" << endl;
    }
    else
    {
        cout << "Not set" << endl;
    }
}

int main()
{
    int n, k;
    cout << "Enter the values: ";
    cin >> n >> k;

    setbit(n, k);
    setbit_2(n, k);
    eff_set_bit(n, k);
    eff_set_bit2(n, k);

    return 0;
}