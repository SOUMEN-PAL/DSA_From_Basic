#include<bits/stdc++.h>
using namespace std;


// naive solution //
void Merge_Intervals(vector<vector<int>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if intervals arr[i] and arr[j] overlap
            if ((arr[i][0] <= arr[j][0] && arr[i][1] >= arr[j][0]) ||
                (arr[j][0] <= arr[i][0] && arr[j][1] >= arr[i][0])) {
                // Merge the overlapping intervals
                arr[i][0] = min(arr[i][0], arr[j][0]);
                arr[i][1] = max(arr[i][1], arr[j][1]);
                
                // Erase the second interval
                arr.erase(arr.begin() + j);
                n--;  // Update the size of the vector
                
            }
        }
    }
}


// Efficient Solution //

bool myComp(vector<int> &arr , vector<int> &brr){
    return arr[0] < brr[0];
}

void mergeIntervals(vector<vector<int>> &arr){
    sort(arr.begin() , arr.end() , myComp);
    int res = 0;
    for(int i = 1 ; i<arr.size() ; i++){
        if(arr[i][0]<=arr[res][1]){
            arr[res][0] = min(arr[res][0] , arr[i][0]);
            arr[res][1] = max(arr[res][1] , arr[i][1]);
        }
        else{
            res++;
            arr[res] = arr[i];
        }
    }
    arr.erase(arr.begin()+res+1 , arr.end());
    for(int i = 0 ; i < arr.size() ; i++){
        cout<<"["<<arr[i][0]<<" "<<arr[i][1]<<"] ";
    }
    
}





int main(){
    vector<vector<int>> arr = { {5,10}, {3,15}, {18,30}, {2,7} };
    Merge_Intervals(arr);
    cout<<"Naive Solution: ";
    for(int i = 0 ; i<arr.size() ; i++){
        cout<<"["<<arr[i][0]<<" "<<arr[i][1]<<"] ";
    }
    cout<<endl;
    cout<<"Efficient Solution: ";
    vector<vector<int>> Array = {{3,4} , {4 , 6} , {6 , 7} , {9 , 10} , {11 , 15} , {12 , 32}};
    mergeIntervals(Array);
    return 0;
}