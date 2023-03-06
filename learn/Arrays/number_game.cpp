#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b , a%b);
    }
}

int num(int n){
    int hcf = 1;
    int res = 1;
    for(int i = 2 ; i<=n ; i++){
        hcf = gcd(i,res);
        res = res*i;
    }
}

int main(){
    



    return 0;
}