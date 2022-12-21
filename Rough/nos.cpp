#include <iostream>
using namespace std;

void prin(int N){
    if(N==false){
        cout<<N;
    }
    else{
        cout<<N<<" ";
        prin(N-1);
    }
}


int main(){
    prin(10);
    
    return 0;
}