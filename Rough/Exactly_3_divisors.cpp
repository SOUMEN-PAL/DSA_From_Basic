#include <iostream>
using namespace std;

int div(int N){
    int c=0,d=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                c++;
            }
        }
        
        if(c==3){
            d++;
        }
        c=0;

    }
    return d;
}


int main(){
    
    cout<<div(6);


    
    return 0;
}