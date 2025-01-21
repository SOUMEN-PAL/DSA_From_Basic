#include<bits/stdc++.h>
using namespace std;
long long int res = 0;
long long sol(long long a, long long b) {
    while (b != 0) {
        res += a / b;
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


int main(){
    long long  a, b;
    cin>>a>>b;

    int x = max(a,b);
    int y = min(a,b);

    auto ans = sol(a , b);
    cout<<res<<endl;

    return 0;
}