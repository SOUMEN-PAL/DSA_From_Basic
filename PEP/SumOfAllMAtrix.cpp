#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &arr) {
    int sum = 0, n = arr.size();
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) { 
            int top_left = (i + 1) * (j + 1); 
            int bottom_right = (n - i) * (n - j); 
            sum += (top_left * bottom_right * arr[i][j]); 
        }
    return sum;
}

int main(){
    
    return 0;
}