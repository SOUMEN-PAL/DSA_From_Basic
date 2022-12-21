#include <iostream>
using namespace std;

int main(){
        for(int i=65;i<65+5;i++){
            for(int k=5-i;k>0;k--){
                cout<<" ";
            }
            for(int j=65;j<=i;j++){
                cout<<char(j)<<" ";
            }
            cout<<endl;
        }
    


    return 0;
}