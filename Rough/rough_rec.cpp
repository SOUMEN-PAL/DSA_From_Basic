#include <bits/stdc++.h>
using namespace std;

unsigned int foo(unsigned int n , unsigned int r){

    if(n>0){return (n%r +foo(n/r , r));}

    else{
        return 0;
    }
}

int main(){
    cout<<foo(513,2);

    return 0;
}