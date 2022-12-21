#include <iostream>
using namespace std;

int main(){
    
    for(int i=1;i<=5;i++){
        for(int k=5-i;k>0;k--){
            cout<<" ";
        }
        for(int j=1;j<=i*2-1;j++){
            int x=64+j;
            
            cout<<char(x);
        }
        cout<<endl;
    }



    return 0;
}