#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

//Recurssive COde

int ways(int n , int maxNum){
    if(n == 0){
        return 1;
    }
    if(n < 0 || maxNum == 0){
        return 0;
    }
    
    return ways(n-maxNum , maxNum) + ways(n, maxNum-1);
}

// memoised Code
vector<vector<int>> memo(1e3+1 , vector<int>(1e3 , -1));
int mod = 1e9+7;
int ways_memo(int n , int mN){
    if(n == 0){
        return 1;
    }
    if(n < 0 || mN == 0){
        if( n >= 0 && mN >=0){
            return memo[n][mN] = 0;
        }
        return 0;
    }
    
    if(memo[n][mN] != -1){
        return memo[n][mN];
    }
    
    return memo[n][mN] = (ways_memo(n - mN , mN) + ways_memo(n , mN-1))%mod;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    cout<<ways(n, n-1)<<endl;
    
    return 0;
}