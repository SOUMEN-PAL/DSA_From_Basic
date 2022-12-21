#include <iostream>
using namespace std;

long long int gcd(int a , int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}


int main(){
    
    int a,b;
    cout<<"Enter values of the nos: ";
    cin>>a>>b;
    cout<<"The GCD of "<<a<<" and "<<b<<" is: "<<gcd(a,b)<<endl;

    
    return 0;
}