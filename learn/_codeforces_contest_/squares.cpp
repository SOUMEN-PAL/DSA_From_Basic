#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        
        int a , b , x , y;
        cin>>a>>b>>x>>y;
        if(a == b && b == x && x == y){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }        
        
        
        
    }

    
    return 0;
}