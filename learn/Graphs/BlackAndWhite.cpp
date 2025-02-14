#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
ll mod = 1e9 + 7;

long long numOfWays(int N, int M)
{
    // write code here
    
    ll totalWays = (ll)(M*N-1)%mod;
    ll atackWays = 0;
    ll res = 0;
    
    int dirX[] = {-2 , -2 , -1 , 1 , 2 , 2 , 1 , -1};
    int dirY[] = {-1 , 1 , 2 , 2 , 1 , -1 , -2 , -2};

    
    for(int i = 0 ; i<N ; i++){
        for(int j = 0 ; j<M ; j++){
            int cnt = 0;
            for(int k = 0 ; k<8 ; k++){
                int nx = i + dirX[k];
                int ny = j + dirY[k];
                
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    cnt++;
                }
            }   
            res  = (res + (totalWays - cnt + mod)%mod)%mod;
            atackWays = (atackWays + cnt)%mod;
        }
    }
    
    ll validWays = (totalWays - atackWays + mod)%mod;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    




    return 0;
}