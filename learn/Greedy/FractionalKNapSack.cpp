#include<bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int>& a, pair<int, int>& b) {
    return ((double)a.first / a.second) > ((double)b.first / b.second);
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    // Your code here
    vector<pair<int, int>> arr;
    int n = val.size();
    for (int i = 0; i < n; i++) {
        arr.push_back({ val[i] , wt[i] });
    }

    sort(arr.begin(), arr.end(), myComp);

    double res = 0;
    int currCap = capacity;

    for (int i = 0; i < n; i++) {
        if (arr[i].second <= currCap) {
            currCap -= arr[i].second;
            res += double(arr[i].first);
        }
        else {
            res += arr[i].first * ((double)currCap / arr[i].second);
            break;
        }
    }
    return res;
}

int main() {
    vector<int> val = {60 , 100 , 120};
    vector<int> wt = {10 , 20 , 30};
    int capacity = 50;

    cout<<fractionalKnapsack(val , wt , capacity)<<endl;

    return 0;
}