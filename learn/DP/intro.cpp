#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


int knapSack(vector<int> val , vector<int> weight , int W , int i){
    if(i == val.size() || W == 0){
        return 0;
    }

    if(weight[i] > W){
        return knapSack(val , weight , W , i+1);
    }
    else{
        return max(
            val[i] + knapSack(val , weight , W - weight[i] , i+1),
            knapSack(val , weight , W , i+1)
        );
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}