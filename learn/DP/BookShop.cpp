#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int helper(vector<int> cost , vector<int> pages , int x , int cst , int sum , int i){
    if(static_cast<size_t>(i) >= cost.size()){
        return cst<=x?sum:0;
    }
    
    if(cst > x){
        return -1e9;  // Use a value that cannot be the answer
    }
    
    
    //take
    int take = helper(cost , pages , x , cst + cost[i] , sum + pages[i] , i+1);
    
    
    //not take
    int notTake = helper(cost , pages , x , cst , sum , i+1);
    
    return max(take , notTake);
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , x;
    cin>>n>>x;
    vector<int> cost(n);
    vector<int> pages(n);
    for(int i = 0 ; i<n ; i++){
        cin>>cost[i];
    }
    
    for(int i = 0; i<n ; i++){
        cin>>pages[i];
    }
    
    int ans = helper(cost , pages , x , 0 , 0 , 0);
    cout<<ans<<endl;
    
    return 0;
}