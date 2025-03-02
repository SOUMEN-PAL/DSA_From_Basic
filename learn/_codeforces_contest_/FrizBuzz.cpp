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
        ll cnt = n/15;
        ll cnt2 = n%15;
        ll res = cnt * 3;

        ll extra = min((ll)3 , cnt2 + 1);
        ll ans = res + extra;
        cout<<ans<<endl;
    }
    
    return 0;
}