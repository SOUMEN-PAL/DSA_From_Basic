#include <iostream>
using namespace std;

// Naive solution //
long long pow(int x, int n)
{
    long long res = x; // long long can be used for getting a large value but its not efficient //
    for (int i = 1; i < n; i++)
    {
        res = res * x;
    }
    return res;
}
// effective recurssive solution tc=log(n) auxalary space=log(n)//
// buts its an overhead function //
int effpow(int x, int n)
{
    if (n == 0)
    {

        return 1;
    }
    int temp = effpow(x, n / 2);
    temp = temp * temp; // here is also temp is preaparing the values for the odd even values of n //
   
    if (n % 2 == 0)
    {
        return temp;
    }
    else
    {
        return temp * x;
    }
}

// itreative solution T.C=O(logn) SP.C=theta(1)//
int power(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n&1){
            res=res*x; // res Odd waleh part ka phele hi confiugration ho chuka hoga //
        }
        x=x*x;
        n=n>>1;
    }
    return res;
}

int main()
{

    int x = pow(4, 2);
    cout << x << endl;
    int y = effpow(4, 2);
    cout << y << endl;
    int z=power(4,2);
    cout<<z<<endl;

    return 0;
}