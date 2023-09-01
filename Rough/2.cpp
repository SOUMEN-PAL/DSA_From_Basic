#include <bits/stdc++.h>
using namespace std;



void threeWayPartition(vector<int>& array,int a, int b)
    {
        int l = 0, r = array.size() - 1;
        for (int i = 0; i <= r; ) {
            if (array[i] < a) {
                swap(array[i], array[l]);
                l++;
                i++;
            }
            else if (array[i] > b) {
                swap(array[i], array[r]);
                r--;
            }
            else {
                i++;
            }
        }
        
    }
        

int main(){
    
    vector<int> arr = {30 ,47 ,91 ,48 ,71 ,52 ,81 ,32 ,94 ,58 ,28 ,13 ,87 ,15 ,56 ,13 ,91 ,13 ,80};
    threeWayPartition(arr , 11 , 30);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}