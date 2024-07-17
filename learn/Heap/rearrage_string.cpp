#include<bits/stdc++.h>
using namespace std;

struct myComp{
    bool operator()(pair<char , int> &a , pair<char , int> &b){
        return b.second > a.second; // wans it as max heap;
    }
};


string rearrange(string s){
    string res = "";
    unordered_map<char , int> hm;
    for(int i = 0  ; i<s.length() ; i++){
        hm[s[i]]++;
    }

    priority_queue<pair<char , int> , vector<pair<char , int>> , myComp> pq;
    for(auto i : hm){
        pq.push({i.first , i.second});
    }
    pair<char , int> prev = {-1 , 0};
    
    while(!pq.empty()){
       
        auto current = pq.top();
        pq.pop();

        res += current.first;

        if(prev.second > 0){
            pq.push(prev);
        }

        current.second--;
        prev = current;
        
    }

    return res;
}



int main(){
    string s = "geeksforgeeks";

    string res = rearrange(s);

    cout<<res<<endl;
    
    return 0;
}