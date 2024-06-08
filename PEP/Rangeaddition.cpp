#include<bits/stdc++.h>
using namespace std;

vector<int> rangeAddition(vector<vector<int>> v , int n){
    vector<int> res(n , 0);
    int s = v.size();
    for(int i = 0 ; i<s ; i++){
        int start = v[i][0] , end = v[i][1] , value = v[i][2];
        res[start] += value;

        if(end+1 < n){
            res[end] -= -1 * value;
        }

    }
}


int main(){
    
    return 0;
}