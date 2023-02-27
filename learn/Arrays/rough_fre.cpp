#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int , int> ans;
    for(int i = 1 ; i<=5 ; i++){
        ans[i] = 0;
    }
    map<int , int> :: iterator it = ans.begin();

    
    for(it ; it!=ans.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl;
  
    } 
    



    return 0;
}