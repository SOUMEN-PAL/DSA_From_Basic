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
int table[256];
void initialize(void){
    table[0]=0;
    for(int i = 1 ; i<256 ; i++){
        table[i] = table[i&(i-1)]+1;
    }
}
int CBIT(int n){
    initialize();
    
    return table[n&255]+table[(n>>8)&255]+table[(n>>16)&255]+table[n>>24];


}

int main()
{

    int x = Countbit(31);
    int y = countSETbits(31);
    int z = CBIT(31);
    cout << x << " " << y << " " << z <<endl;

    return 0;
}