#include <bits/stdc++.h>
using namespace std;
int posOfRightMostDiffBit(int m, int n)
{
    // Your code here
    // int a = max(m,n);
    int msb = log2(m);
    int count=0;
    while(msb>=0){
        unsigned int x=m&1;
        unsigned int y=n&1;
        if(x!=y){
            return count+1;
        }
        
        count++;
        msb--;
        m=m>>1;
        n=n>>1;
    }
    return -1;
}



int main(){
    cout<<posOfRightMostDiffBit(8,0);



    return 0;
}