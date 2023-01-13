#include <iostream>
using namespace std;

int Countbit(int n){
    int set=0;
    while(n>0){
        if(n&1!=0){
            set=set+1;
        }
        n=n>>1;
    }
    return set;
}

int main(){
    int x=Countbit(10);
    cout<<x<<endl;
    


    return 0;
}