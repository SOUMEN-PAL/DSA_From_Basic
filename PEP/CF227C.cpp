#include<bits/stdc++.h>
using namespace std;



long long power(long long N,long long R , long long mod)
{
    if(R==0){
    return 1;
    }
    if(N==1){
    return 1;
    }
long long res=power(N,R/2,mod)%mod;
if(R%2==0){
    return (res*res)%mod;
}
else{
    return (((res*res)%mod)*N)%mod;
}

}

long long toh(long long N, int from, int to, int aux , long long mod) {
     // Your code here
    long long ans = power(3 , N , mod); 
    if(ans == 0){
        return mod-1;
    }
    return ans-1;
}   


int main(){
    long long n , mod;
    cin>>n>>mod;

    long long ans = toh(n , 3 , 2 , 1 , mod);
    
    cout<<ans%mod<<endl;
    
    return 0;
}