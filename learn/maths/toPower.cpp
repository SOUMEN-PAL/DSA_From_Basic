#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long power(int N,int R)
{
    if(R==0){
      return 1;
    }
    if(N==1){
      return 1;
    }
  long long res=power(N,R/2)%mod;
  if(R%2==0){
      return (res*res)%mod;
  }
  else{
      return (((res*res)%mod)*N)%mod;
  }
    
}

int main(){
    
    return 0;
}


