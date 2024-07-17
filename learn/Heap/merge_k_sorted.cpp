#include<bits/stdc++.h>
using namespace std;

class helper{
    public:
    int value = 0 , arrIndex = 0 , elementIndex = 0;
};

struct myComp{
    bool operator()(const helper& a , const helper& b){
        return b.value < a.value;
    }
};

vector<int> merge_k_sorted(vector<vector<int>> arr){
    priority_queue<helper , vector<helper> , myComp> pq;
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        int value = arr[i][0];
        int arrIndex = i;
        int elementIndex = 0;

        helper temp;
        temp.value = value;
        temp.arrIndex = arrIndex;
        temp.elementIndex = elementIndex;

        pq.push(temp);
    }

    vector<int> res;
    while(!pq.empty()){
        helper t = pq.top();
        res.push_back(t.value);
        pq.pop();
        helper temp;
        temp.arrIndex = t.arrIndex;
        if(t.elementIndex + 1 < arr[t.arrIndex].size()){
            temp.elementIndex = t.elementIndex + 1;
            temp.value = arr[temp.arrIndex][temp.elementIndex];
            pq.push(temp);
        }

    }

    return res;
}


int main(){

    
    vector<vector<int>> arr = {{2, 6, 12, 34},
                                {1, 9, 20, 1000},
                                {23, 34, 90, 2000}};
    vector<int> res = merge_k_sorted(arr);
    for(auto x : res){
        cout<<x<<" ";
    }


    return 0;
}