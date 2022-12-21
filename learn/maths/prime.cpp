#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int a){
    if (a==1){
        return false;
    }

    for(int i=2 ; i<=pow(a,0.5) ;i++){
        if (a%i==0){
            return false;
        
        }
    
    }
    return true;
}


int main(){
    
int a;
cout<<"Enter a no: ";
cin>>a;
int x=isprime(a);
if (x==1){
    cout<<"Its a prime no"<<endl;
}
else{
    cout<<"Its not a prime no"<<endl;
}




    
    return 0;
}