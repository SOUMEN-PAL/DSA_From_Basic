#include <iostream>
using namespace std;

void prime(int n){
    for (int i=1;i<=n;i++){
        bool x=true;
        for(int j=2;j<i;j++){
            if(i%j==0){
                x=false;
                break;
            }
            
        }
        if(x==true){
            cout<<i<<" ";

        }
        
    }
}


int main(){
    
    prime(12);  



    return 0;
}