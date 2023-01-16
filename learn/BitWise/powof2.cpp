#include <iostream>
using namespace std;

// naive solution //
bool power(int n){
    if(n==0){
        return false;
    }
    while(n!=1){
        if(n%2!=0){
            return false;
        }
        n=n/2;
    }
    return true;
}

// efficient solution //


bool pow2(int n){
    return (n && (n&(n-1))==0);
}

int main(){
    cout<<pow2(64)<<endl;
    cout<<power(63)<<endl;;
    
    return 0;
}