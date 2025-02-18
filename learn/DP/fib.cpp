#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int fibo(int n){
    vector<int> fib(n+2);

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2 ; i<=n ; i++){
        fib[i] = fib[i-1] + fib[i-2]; // the subproblems are being optimised here //
    }

    return fib[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fibo(5)<<endl;
    return 0;
}