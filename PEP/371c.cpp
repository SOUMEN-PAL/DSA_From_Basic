#include<bits/stdc++.h>
using namespace std;

int main(){
    long mod = 1e9 + 7;
    string s;
    int pb, ps , pc;
    int cb , cs , cc;
    long long r;
    cin>>s;
    cin>>pb>>ps>>pc>>cb>>cs>>cc>>r;
    int len = s.length();

    long long cntS , cntB , cntC;
    cntS = cntB = cntC = 0;

    for(int i = 0 ; i<len ; i++){
        if(s[i] == 'B'){
            cntB++;
        }
        else if(s[i] == 'C'){
            cntC++;
        }
        else{
            cntS++;
        }
    }
    // cout<<cntB<<" "<<cntS<<" "<<cntC<<endl;
    long long makingPrice =( ((cntB*cb)%mod) + ((cntC*cc)%mod) + ((cntS*cs)%mod))%mod;
    long BPrice = 0 , SPrice = 0 , CPrice = 0;
    if(cntB>0){
        BPrice = cb*pb;
    }
    if(cntC>0){
        CPrice = cc*pc;
    }
    if(cntS){
        SPrice = cs*ps;
    }

    long long qtyPrice = BPrice+SPrice+CPrice;

    qtyPrice = (qtyPrice + r);

    // cout<<makingPrice<<" "<<qtyPrice<<endl;
    cout<<qtyPrice/makingPrice<<endl;

    return 0;
}