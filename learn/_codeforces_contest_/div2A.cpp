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
        ll n;
        cin>>n;
        if(n%3 == 1){
            cout<<"YES"<<endl;
            
        }
        else{
            cout<<"NO"<<endl;
        }        
    }
    
    return 0;
}