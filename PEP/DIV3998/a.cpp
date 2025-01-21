#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int cntFibo = 0;
        int a , b , d , e;
        cin>>a>>b>>d>>e;

        //need to find c so that a + b = c or b + c = d or c + d = e
        int c = d - b;
        
        if(a+b == c){
            cntFibo++;
        }
        if(b+c == d){
            cntFibo++;
        }
        if(c+d == e){
            cntFibo++;
        }
        cout<<cntFibo<<endl;
    }


    return 0;
}