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


/*
int helper(vector<int>& cost, vector<int>& pages, int remainingMoney, int idx) {
    if (idx >= cost.size()) {
        return 0;
    }
    
    if (remainingMoney < 0) {
        return -1e9;  // Invalid state
    }
    
    // Take current book if we have enough money
    int take = (remainingMoney >= cost[idx]) ? 
               pages[idx] + helper(cost, pages, remainingMoney - cost[idx], idx + 1) : -1e9;
    
    // Don't take current book
    int notTake = helper(cost, pages, remainingMoney, idx + 1);
    
    return max(take, notTake);
}
*/

int overhead_recurssion(vector<int> &cost , vector<int> &pages , int money , int idx){
    if(static_cast<size_t>(idx) >= cost.size()){
        return 0;
    }
    
    if(money < 0){
        return -1e9;
    }
    
    int take = -1e9;
    if(money >= cost[idx]){
        take = pages[idx] + overhead_recurssion(cost , pages , money - cost[idx] , idx + 1);
    }
    
    int notTake = overhead_recurssion(cost , pages , money , idx + 1);
    
    return max(take , notTake);
}


//Memoised COde//
vector<vector<int>> memo;
int memo_code(const vector<int> &cost , const vector<int> &pages , int money , int idx){
    if(static_cast<size_t>(idx) >= cost.size()){
        return 0;
    }
    
    if(money < 0){
        return -1e9;
    }
    
    if(memo[idx][money] != -1){
        return memo[idx][money];
    }
    
    int take = -1e9;
    if(money >= cost[idx]){
        take  = pages[idx] + memo_code(cost , pages , money - cost[idx] , idx + 1);
    }
    
    int notTake = memo_code(cost , pages , money , idx+1);
    
    return memo[idx][money] = max(take , notTake);
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
    
    // int ans = helper(cost , pages , x , 0 , 0 , 0);
    // cout<<ans<<endl;
    
    // int solution = overhead_recurssion(cost , pages , x , 0);
    // cout<<solution<<endl;
    
    memo.assign(n , vector<int>(x+1 , -1));
    int memo_ans = memo_code(cost , pages , x , 0);
    cout<<memo_ans<<endl;
    
    return 0;
}