#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        int m = (int)floor(log2(x));
        ll base = 1LL << m;
        ll r = x - base;
        if(r == 0 || r == base - 1){
            cout << -1<<endl;
            continue;
        }
        int iBit = -1;
        for (int i = 0; i < m; i++){
            if(r & (1LL<<i)){
                iBit = i;
                break;
            }
        }
        int jBit = -1;
        for (int j = 0; j < m; j++){
            if(!(r & (1LL << j))){
                jBit = j;
                break;
            }
        }
        //2^i and 2^j haaan yeh for calculation
        ll y = (1LL << iBit) + (1LL << jBit);
        cout << y << "\n";
    }
    return 0;
}
