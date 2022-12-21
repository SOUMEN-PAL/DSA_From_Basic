#include <iostream>
#include <math.h>
using namespace std;

int count(int n){
    if(n<0){
        return 0;
    }
    if (n<=1){
        return 1;
    }

    double m=0;
    for(int i=1;i<=n;i++){
        m=m+log10(i);
    }
    

    return floor(m+1);
}

int main(){
    
    int n;
    cout<<"Enter the value: ";
    cin>>n;
    cout<<count(n);


    return 0;
}