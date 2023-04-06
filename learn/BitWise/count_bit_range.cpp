#include<bits/stdc++.h>
using namespace std;

int count_inrange(int n){
    if(n==0 || n==1){
        return n;
    }
    int msb = floor(log2(n));
    return (msb*(1<<msb-1)) + ((n-(1<<msb))+1) + count_inrange(n-(1<<msb)); 
}


int main()
{
    cout<<count_inrange(4);



    return 0;
}