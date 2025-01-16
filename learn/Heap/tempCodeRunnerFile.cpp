#include<bits/stdc++.h>
using namespace std;

struct myComp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // Example comparison: compare based on the first element of the pair
        return a.first > b.first;
    }
};

int main(){
    // vector<int> arr = {1,2,3,4,5,6};
    // priority_queue<int , vector<int> , greater<int>> pq(arr.begin() , arr.end());

    // while(!pq.empty()){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }

    unordered_map<int , int> mp;
    mp[1] = 2;
    mp[2] = 40;
    mp[5] = 10;


    priority_queue<pair<int , int> , vector<pair<int , int> , myComp>> pq;
    for(auto i : mp){
        pq.push({i.first , i.second});
    }

    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }



    return 0;
}