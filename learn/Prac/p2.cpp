#include <bits/stdc++.h>
using namespace std;




int main(){
    
    vector<vector<int>> arr = {
        {10 ,20,30,40},
        {27,29,37,48},
        {15,85,96,34},
        {32,33,39,50}
    };
    sort(arr.begin() , arr.end());
    
    for(auto i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }




    return 0;
}