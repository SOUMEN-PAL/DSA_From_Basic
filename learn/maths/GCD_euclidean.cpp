#include <iostream>
using namespace std;

int GCD(int a,int b){
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}


int main(){
    
    int a,b;
    cout<<"Enter the valyues for GCD: ";
    cin>>a>>b;
    cout<<"The GCD/HCF is: "<<GCD(a,b);



    return 0;
}