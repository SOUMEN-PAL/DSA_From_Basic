#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<vector<int>> arr(4 , vector<int>(2));

    // Take input for all the values
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    // Print the values
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
     


    return 0;
}