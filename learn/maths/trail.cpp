#include <iostream>
using namespace std;


long long int trail(int n){
    long long int res=0;
    for(int i=5;i<=n;i=i*5){
        res=res+n/i;
    }
    return res;
}


int main(){
    int n;
    cout<<"Whose factorial trailing zeros you want: ";
    cin>>n;
    cout<<trail(n);
    cout<<endl;
    return 0;
}