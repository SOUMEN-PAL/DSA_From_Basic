#include<bits/stdc++.h>
using namespace std;

// naive solution //
int median(vector<vector<int>> &arr , int r , int c)
{
    vector<int> nums;
    for(int i = 0 ; i<r ; i++){
        for(int j = 0 ; j<c ; j++){
            nums.push_back(arr[i][j]);
        }
    }
    sort(nums.begin() , nums.end());
    return nums[(r*c)/2];
}


// Efficient Solution //
int upperBound(vector<int> arr , int x){
    int low = 0 , high = arr.size();
    int res = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>x){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

int medianMatrix(vector<vector<int>> &arr , int r , int c){
    int minElelment = arr[0][0] , maxElement = arr[0][c-1];
    for(int i = 0 ; i<r ; i++){
        maxElement = max(maxElement , arr[i][c-1]);
        minElelment = min(minElelment , arr[i][0]);
    }
    int medPos = ((r*c)+1)/2;
    while(minElelment<=maxElement){
        int mid = (minElelment+maxElement)/2;
        int midPos = 0;
        for(int i = 0 ; i<r ; i++){
            midPos += upperBound(arr[i] , mid);
        }
        if(midPos<medPos){
            minElelment = mid + 1;
        }
        else{
            maxElement = mid;
        }
    }
    return minElelment;
}



int main(){
    vector<vector<int>>arr = {
        {5,10,20,30,40},
        {1,2,3,4,6},
        {11,13,15,17,19}
    };
    int r = arr.size();
    int c = arr[0].size();
    cout<<median(arr , r , c)<<endl;
    cout<<medianMatrix(arr , r , c)<<endl;
    
    return 0;
}