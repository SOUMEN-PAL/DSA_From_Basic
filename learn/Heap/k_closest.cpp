#include<bits/stdc++.h>
using namespace std;

// Naive solution 
void k_closest(int arr[], int n, int k, int x) {
    bool visited[n] = {false};

    for(int i = 0; i < k; i++) {
        int closest_ele = INT_MAX;
        int closest_ele_indx = 0;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && abs(arr[j] - x) < closest_ele) {
                closest_ele_indx = j;
                closest_ele = abs(arr[j] - x);
            }
        }

        cout << arr[closest_ele_indx] << " ";
        visited[closest_ele_indx] = true;
    }
}



//Efficient solution 

void closest(int arr[] , int n , int k , int x){
    priority_queue<pair<int , int>> pq;
    for(int i = 0 ; i<k ; i++){
        pq.push({abs(arr[i] -x ) , i});
    }

    for(int i = k ; i<n ; i++){
        int diff = abs(arr[i] - x);
        if(pq.top().first > diff){
            pq.pop();
            pq.push({diff , i});
        }
    }

    while(!pq.empty()){
        int i = pq.top().second;
        cout<<arr[i]<<" ";
        pq.pop();
    }
}

int main() {
    int arr[] = {10, 30, 5, 40, 38, 80, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int x = 11;

    closest(arr, n, k, x);

    return 0;
}
