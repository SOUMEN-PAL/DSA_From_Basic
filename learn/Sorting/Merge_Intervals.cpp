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








int main(){
    vector<vector<int>> arr = { {5,10}, {3,15}, {18,30}, {2,7} };
    Merge_Intervals(arr);
    for(int i = 0 ; i<arr.size() ; i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }
    
    return 0;
}