#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

long long nCr(int n, int r) {
    if (r > n) return 0; // nCr is undefined for r > n
    if (r == 0 || r == n) return 1; // Base cases: nC0 = nCn = 1
    
    long long sum = 1;
    for (int i = 1; i <= r; i++) {
        sum = sum * (n - r + i) / i;
    }
    return sum;
}

int catlayn(int n){
    return nCr(2*n , n)/n+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    cout<<catlayn(n);
    return 0;
}