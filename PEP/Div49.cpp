#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 998244353;
//Writen by sidbo_t don not copy
struct BIT {
    int n;
    vector<ll> fenw;
    BIT(int n) : n(n) {
        fenw.assign(n+1, 0);
    }
    void update(int i, ll delta) {
        for(; i <= n; i += i & (-i)) {
            fenw[i] = (fenw[i] + delta) % MOD;
            if(fenw[i] < 0) fenw[i] += MOD;
        }
    }
    ll query(int i) {
        ll sum = 0;
        for(; i > 0; i -= i & (-i))
            sum = (sum + fenw[i]) % MOD;
        return sum;
    }
    ll range_query(int l, int r) {
        if(l > r) return 0;
        return (query(r) - query(l-1) + MOD) % MOD;
    }
};
 
ll modexp(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
 
        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++){
            cin >> queries[i];
        }
 
        vector<ll> A(n+1), B(n+1);
        for (int i = 1; i <= n; i++){
            A[i] = modexp(2, i-1, MOD);
        }
        for (int i = 1; i <= n; i++){
            B[i] = modexp(2, n-i, MOD);
        }
 
        ll constPart = (modexp(2, n, MOD) - 1 + MOD) % MOD;
 
        ll T_val = 0;
        ll prefix0 = 0, prefix1 = 0;
        for (int j = 1; j <= n; j++){
            if(s[j-1]=='0'){
                T_val = (T_val + prefix1 * B[j]) % MOD;
                prefix0 = (prefix0 + A[j]) % MOD;
            } else {
                T_val = (T_val + prefix0 * B[j]) % MOD;
                prefix1 = (prefix1 + A[j]) % MOD;
            }
        }
 

        BIT bitA0(n), bitA1(n), bitB0(n), bitB1(n);
        for (int i = 1; i <= n; i++){
            if(s[i-1]=='0'){
                bitA0.update(i, A[i]);
                bitB0.update(i, B[i]);
            } else {
                bitA1.update(i, A[i]);
                bitB1.update(i, B[i]);
            }
        }
 
        vector<ll> ans;
        ans.reserve(q);
 
        for (int qi = 0; qi < q; qi++){
            int pos = queries[qi]; 
            char oldc = s[pos-1];
            char newc = (oldc=='0' ? '1' : '0');
 
            ll L0 = bitA0.query(pos-1);
            ll L1 = bitA1.query(pos-1);
            ll R0 = bitB0.range_query(pos+1, n);
            ll R1 = bitB1.range_query(pos+1, n);
 
            ll delta = 0;
            if(oldc=='0' && newc=='1'){
                delta = (A[pos] * ((R0 - R1) % MOD) + B[pos] * ((L0 - L1) % MOD)) % MOD;
            } else if(oldc=='1' && newc=='0'){
                delta = (A[pos] * ((R1 - R0) % MOD) + B[pos] * ((L1 - L0) % MOD)) % MOD;
            }
            delta = (delta % MOD + MOD) % MOD;
 
            T_val = (T_val + delta) % MOD;
 
            if(oldc=='0'){
                bitA0.update(pos, -A[pos]);
                bitB0.update(pos, -B[pos]);
                bitA1.update(pos, A[pos]);
                bitB1.update(pos, B[pos]);
            } else {
                bitA1.update(pos, -A[pos]);
                bitB1.update(pos, -B[pos]);
                bitA0.update(pos, A[pos]);
                bitB0.update(pos, B[pos]);
            }
 
            s[pos-1] = newc;
 
            ll curAns = (constPart + T_val) % MOD;
            ans.push_back(curAns);
        }
 
        for (int i = 0; i < q; i++){
            cout << ans[i] << (i+1==q? "\n" : " ");
        }
    }
    return 0;
}
