#include <iostream>
using namespace std;

int fac(int n){
    int x=1;
    for(int i=n;i>0;i--){
        x=x*i;
// one way is to use for loop //
    }
    return x;
}

int factorial(int n){
    
    if(n<=0){
        return 1;   
    }
// using recurssion //
    else{
        return n*factorial(n-1);
    }
}

void facc(int n){
    int i=n;
    int x=1;
    while(i>0){
        x=x*i;
        i--;
    }
    cout<<"The facc is: "<<x<<endl;
}

int main(){
    int n;
    cout<<"Enter the no: ";
    cin>>n;
    cout<<fac(n)<<endl;
    cout<<"The factorial is: "<<factorial(n)<<endl;
    facc(n);

    
    return 0;
}