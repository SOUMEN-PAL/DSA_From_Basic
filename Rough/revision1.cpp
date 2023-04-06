#include<bits/stdc++.h>
using namespace std;

int T[256];
void look(){
    T[0]=0;
    for(int i = 1 ; i<256 ; i++){
        T[i] = T[i&(i-1)]+1;
    }


}

int count_setbit(int n){
    look();

    return(T[n&255]+
        T[(n>>8)&255]+
        T[(n>>16)&255]+
        T[n>>24]);
}


int main()
{
    cout<<count_setbit(5);
    return 0;
}