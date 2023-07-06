#include<bits/stdc++.h>
using namespace std;

vector<int> twoRepeated(int arr[], int N) {
    vector<int>ans;
    for(int i = 0 ; i<N+2 ; i++){
        int x = abs(arr[i]);
        if(arr[x]>0){
            arr[x] = -arr[x];
        }
        else{
            ans.push_back(x);
        }
    }
    return ans;
}


int main() {
    int arr[] = { 1,2,1,3,4,3 };
    int n = 4;
    vector<int> res = twoRepeated(arr, n);
    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}