#include<bits/stdc++.h>
using namespace std;

// naive solution //
vector<int> spanStock(vector<int> arr){
    int n = arr.size();
    vector<int> res;
    for(int i = 0 ; i<n ; i++){
        int span = 0;
        for(int j = i ; j>=0 && arr[j]<=arr[i] ; j--){
            span++;
        }
        res.emplace_back(span);
    }
    return res;
}

// Efficient solution //

vector<int> spanStockEff(vector<int> arr){
    vector<int> res;
    stack<int> s;
    s.push(0);// Pushing the indexes //
    res.push_back(1);
    for(int i = 1 ; i<arr.size() ; i++){
        while(s.empty() == false && arr[s.top()]<=arr[i]){
            s.pop();
        }

        int span = s.empty() ? i+1 : i - s.top();
        res.push_back(span);
        s.push(i);
    }
    return res;
}


int main(){
    vector<int> v = {13 , 15 , 12 , 14 , 16 , 8 , 6 , 4 ,10 , 30};
    vector<int> res = spanStockEff(v);
    for(int i : res){
        cout<<i<<" ";
    }
    return 0;
}