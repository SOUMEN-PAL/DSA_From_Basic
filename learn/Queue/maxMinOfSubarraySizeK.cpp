#include<bits/stdc++.h>
using namespace std;

// Sliding window + Custom DS //

// Naive solution //
void maxMinOfSubarray(int arr[] , int n , int k){
    for(int i = 0 ; i<=n-k ; i++){
        int mx = arr[i];
        for(int j = i+1 ; j<i+k ; j++){
            mx = max(mx , arr[j]);
        }
        cout<<mx<<" ";
    }
    cout<<endl;
}

// Efficient Solution //

void MaxOfEverySubarrayOfSizeK(int arr[] , int n , int k){
    deque<int> dq;
    for(int i = 0 ; i<k ; i++){
        while(dq.empty() == false && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = k ; i<n ; i++){
        cout<<arr[dq.front()]<<" "; // Printing for the previous sub array //

        // Better idea to couter the problem of removing the numbers that are out of the window and we are using index in dq to determin it //
        while(dq.empty() == false && dq.front()<=i-k){
            dq.pop_front();
        }

        while(dq.empty() == false && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);

    }
    // Printing for the last k size subarray //
    cout<<arr[dq.front()]<<" "; // Printing for the previous sub array //

}


int main(){
    int arr[] = {1 ,2 ,3 ,1 ,4 ,5 ,2 ,3 ,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    maxMinOfSubarray(arr , n , k);
    MaxOfEverySubarrayOfSizeK(arr , n , k);
    cout<<endl;
    return 0;
}