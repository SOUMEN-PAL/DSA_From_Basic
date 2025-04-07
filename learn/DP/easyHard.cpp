#include<bits/stdc++.h>
#include <sys/types.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


int easyHard(int n , vector<int> easy , vector<int> hard , int i , int score , bool previouslyTaken){
    if(i == n){
        return score;
    }
    
    int notTaken = easyHard(n , easy , hard , i+1 , score , false);
    
    int taken = 0;
    if(previouslyTaken == true){
        taken = easyHard(n , easy , hard , i+1 , score + easy[i] , true);
    }
    else{
        int takeEasy = easyHard(n, easy, hard, i+1, score + easy[i], false);
        int takeHard = easyHard(n, easy, hard, i+1, score + hard[i], true);
        taken = max(takeEasy, takeHard);
    }
    
    return max(taken , notTaken);
}

//memoised code
int easyHardDP2(int n, vector<int>& easy, vector<int>& hard, int i, bool previouslyTaken, vector<vector<int>>& dp) {
    if(i == n) {
        return 0;
    }
    
    if(dp[i][previouslyTaken] != -1) {
        return dp[i][previouslyTaken];
    }
    
    int notTaken = easyHardDP2(n, easy, hard, i+1, false, dp);
    
    int taken = 0;
    if(previouslyTaken == true) {
        taken = easyHardDP2(n, easy, hard, i+1, true, dp) + easy[i];
    }
    else {
        int takeEasy = easyHardDP2(n, easy, hard, i+1, false, dp) + easy[i];
        int takeHard = easyHardDP2(n, easy, hard, i+1, true, dp) + hard[i];
        taken = max(takeEasy, takeHard);
    }
    
    return dp[i][previouslyTaken] = max(taken, notTaken);
}

//Tabulation codee

int tabulationCode(int n , vector<int> easy , vector<int> hard){
    vector<vector<int>> dp(n+1 , vector<int>(2 , 0));
    
    for(int i = n-1 ; i>=0 ; i--){
        for(int prevTaken = 0 ; prevTaken <= 1 ; prevTaken++){
            int notTaken = dp[i+1][0];
            
            int taken = 0;
            if(prevTaken == 1){
                taken = dp[i+1][1] + easy[i];
            }
            else{
                int takeEasy = dp[i+1][0] + easy[i];
                int takeHard = dp[i+1][1] + hard[i];
                taken = max(takeEasy, takeHard);
            }
            
            dp[i][prevTaken] = max(taken , notTaken);
        }
    }
    return dp[0][0];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> easy(n) , hard(n);
    
    for(int i = 0 ; i<n ; i++){
        cin>>easy[i]>>hard[i];
    }
    
    int solution = easyHard(n , easy , hard , 0 , 0 , false);
    cout << "Recurssive Solution: " << solution << endl;
    
    vector<vector<int>> memo(n, vector<int>(2, -1));
    solution = easyHardDP2(n, easy, hard, 0, false, memo);
    cout << "Memo Solution: " << solution << endl;
    
    solution = tabulationCode(n , easy , hard);
    cout<<"Tablutaion solution: "<<solution<<endl;
    
    return 0;
}