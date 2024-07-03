#include<bits/stdc++.h>
using namespace std;

//fibonachi using dp 



//fibonachi using recusion
int fibRec(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fibRec(n-1) + fibRec(n-2);
}


int main(){
    
    return 0;
}