#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int modInverse(int a, int m)
{
    //Your code here
    for(int i=1 ; i<=m ; i++){
        if((a*i)%m==1){
            return i;
            break;
        }

    }
    return -1;
}

int nCr(int n, int r) {
    if (r > n) return 0; // nCr is undefined for r > n
    if (r == 0 || r == n) return 1; // Base cases: nC0 = nCn = 1

    long long sum = 1;
    for (int i = 1; i <= r; i++) {
        long long a = (n - r + i)%mod;
        long long b = modInverse(i , mod);

        sum = (sum*(a*b)%mod)%mod;
    }
    return static_cast<int>(sum);
}





int main(){
    
    int n;
    cin>>n;
    long long res = 0;
    long long totalBalls = 0;
    while(n--){
        int a;
        cin>>a;
        
        if(res == 0){
            res = 1;
        }
        else{
            int r = a-1;
            int value = nCr(totalBalls+r , r);
            res = (res*value)%mod;
        }


        totalBalls += a;
    }

    cout<<res<<endl;

    return 0;
}