#include <iostream>
using namespace std;

// ----naive approach to print prime nos----- //
bool isprime(int a){
    if(a==1){return false;}
    if(a==2 || a==3){return true;}
    if(a%2==0 || a%3==0){
        return false;
    }
    for(int i=5;i*i<=a;i+6){
        if(a%i==0 || a%i+2){
            return false;
        }
    }

    return true;


}

int main(){
    
    int m;
    cout<<"Enter a no: ";
    cin>>m;
    for(int i=2; i<=m; i++){
        if(isprime(i)){
            cout<<i<<" ";
        }
    }


    
    return 0;
}