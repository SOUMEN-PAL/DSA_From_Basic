#include<bits/stdc++.h>
using namespace std;

int main(){
    char *c = new char[5];

    for(int i = 0 ; i<5 ; i++){
        cin>>c[i];
    }

    for(int i = 0 ; i<5 ; i++){
        cout<<c + i<<endl;
    }


    return 0;
}