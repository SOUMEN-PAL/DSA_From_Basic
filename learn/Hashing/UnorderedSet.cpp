#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(20);
    s.insert(56);
    auto pos = s.find(20);
    cout<<*pos;
    cout<<s.size()<<endl;

    // unordered_map<string , int> mp;
    // mp["gfg"] = 100;
    // mp.insert({"Hell" , 290});
    // for(auto i : mp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    return 0;
}