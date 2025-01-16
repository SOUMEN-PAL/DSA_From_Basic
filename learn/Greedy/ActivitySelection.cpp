#include<bits/stdc++.h>
using namespace std;

bool myComp(pair<int , int> &a , pair<int , int> &b){
    return (a.second < b.second);
}

int maxActivities(vector<pair<int , int>> arr , int n){
    sort(arr.begin() , arr.end() , myComp);
    int prev = 0;
    int res = 1;
    for(int curr = 1 ; curr<n ; curr++){
        if(arr[curr].first >= arr[prev].second){
            res++;
            prev = curr;
        }
    }
    return res;

}



int main(){
    vector<pair<int , int>> arr = {make_pair(1,2) , make_pair(2,3) , make_pair(3 , 4) , make_pair(5 , 6)};
    int n  = arr.size();

    int ans = maxActivities(arr , n);

    cout<<"The answer is: "<<ans<<endl;
    
    return 0;
}