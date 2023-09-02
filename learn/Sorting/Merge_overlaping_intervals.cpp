#include<bits/stdc++.h>
using namespace std;

// Naive solution O(n^3) //
void Merge_Intervals(vector<vector<int>> &arr){
    
    
    for(int i = 0 ; i<arr.size() ; i++){
        
        for(int j = 0 ; j<arr.size() ; j++){
            
            if(arr[i][0]>=arr[j][0]  &&  arr[i][0]<=arr[j][1]){
                arr[i][0] = arr[j][0];
                arr.erase(arr.begin()+j);
                
            }
            else if(arr[j][0]>=arr[i][0] && arr[j][0]<=arr[i][1]){
                arr[j][0] = arr[i][0];
                arr.erase(arr.begin()+i);
                
            }
            
        }
    }
}


// Efficient Solution //
bool myComp(vector<int> &arr , vector<int> &brr){
    return arr[0]<brr[0];
}

void mergeIntervals(vector<vector<int>> arr){
    sort(arr.begin() , arr.end() , myComp);
    int res = 0;
    for(int i = 1 ; i<arr.size() ; i++){
        if(arr[i][0]<=arr[res][1]){
            arr[res][0] = min(arr[res][0] , arr[i][0]);
            arr[res][1] = max(arr[res][1] , arr[res][1]);
        }
    }

}




int main(){
    vector<vector<int>> arr= {{1,3} ,{9,10} , {2,4} , {5 , 7} , {6 , 8}};
    Merge_Intervals(arr);
    
    for(int i = 0 ; i<arr.size() ; i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }
    

    
    return 0;
}