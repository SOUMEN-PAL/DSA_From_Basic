#include <iostream>
using namespace std;


int countd(int x){
    int res=0;
    while(x>0){
        x=x/10;
        res++;
    }

    return res;
}



int main(){
    int n;
    cout<<"Enter a no: ";
    cin>>n;
    cout<<countd(n);

    return 0;
}