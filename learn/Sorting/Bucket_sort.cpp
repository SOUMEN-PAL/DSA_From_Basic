#include<bits/stdc++.h>
using namespace std;



void bucket_sort(int arr[], int n, int k) {
    int max_value = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_value = max(arr[i], max_value);
    }
    max_value++;
    vector<vector<int>> bkt(k); // 2d vectors or array of vectors //
    for (int i = 0; i < n; i++) {
        int bkti = (k * arr[i]) / max_value;
        bkt[bkti].push_back(arr[i]);
    }

    for(int i = 0 ; i<k ; i++)
    {
        // sorting all the buckets individually //
        sort(bkt[i].begin() , bkt[i].end());
    }
    int index = 0;
    for(int i = 0 ; i<k ; i++){
        for(int j = 0 ; j<bkt[i].size() ; j++){
            arr[index++] = bkt[i][j];
        }
    }
}


int main() {
    int arr[] = {30,40,10,80,5,12,70};
    int n =sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    bucket_sort(arr , n , k);
    for(int i = 0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}