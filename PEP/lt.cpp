#include<bits/stdc++.h>
using namespace std;


//comparater for priority queue
class myComp{
    public:
    bool operator()(vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    }
};

void BFS(vector<vector<int>>& edges , vector<int> &nums , vector<bool> visited , int largestLength){
    
}


vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
    priority_queue<vector<int> , vector<vector<int>> , myComp> pq(edges.begin() , edges.end());

    auto tp = pq.top();
    
    int largestLength = tp[2];


}


int main(){
    
    return 0;
}