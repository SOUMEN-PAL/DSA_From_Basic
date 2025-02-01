#include<bits/stdc++.h>
using namespace std;

/*
Your task is to count the number of integers between a and b where no two adjacent digits are the same.
Input
The only input line has two integers a and b.
Output
Print one integer: the answer to the problem.
Constraints

0 \le a \le b \le 10^{18}

Example
Input:
123 321

Output:
171
*/

vector<vector<vector<int>>> memo;

int fun(int i , int tight , int prev ,  bool leadingZero , string &s){
    if(i == s.size()){
        return 1;
    }
    int ub = tight ? s[i] - '0' : 9;
    int ans = 0;
    for(int j = 0 ; j<=ub ; j++){
        if(!leadingZero && j == prev) continue;
        ans += fun(i + 1 , tight && (j == ub) , j , leadingZero && j == 0 , s);
        
    }
    return ans;
}


int main(){
    int a , b;
    cin>>a>>b;
    string s = to_string(b);
    int ans1 = fun(0 , 1 , -1 , true , s);
    s = to_string(a - 1);
    int ans2 = fun(0 , 1 , -1 , true ,s);
    cout<<ans1 - ans2;



    return 0;
}