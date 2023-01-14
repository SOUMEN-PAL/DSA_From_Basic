#include <iostream>
using namespace std;

int Countbit(int n)
{
    int set = 0;
    while (n > 0)
    {
        if (n & 1 != 0)
        {
            set = set + 1;
        }
        n = n >> 1;
    }
    return set;
}
// Efficient solution Time complexity: O(set bits) //

int countSETbits(int n)
{
    int res = 0;
    while (n > 0)
    {
        n = n & (n - 1);// <----- Brian Keringum's Equation //
        res++;
    }
    return res;
}

// efficient solution Lookup table //

int main()
{
    int x = Countbit(32);
    int y = countSETbits(32);
    cout << x << " " << y << endl;

    return 0;
}