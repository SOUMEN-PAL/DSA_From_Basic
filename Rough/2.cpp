#include <bits/stdc++.h>
using namespace std;



void threeWayPartition(vector<int>& array,int a, int b)
{
    int l = -1 , r = array.size();
    while(true){
        do{
            l++;
        }while(array[l]<a);
        
        do{
            r--;
        }while(array[r]>b);
        if(l>=r){
            break;
        }
        swap(array[l] , array[r]);
    }
    l = -1;
    r = array.size();
    while(true){
        do{
            l++;
        }while(array[l]<b);
        
        do{
            r--;
        }while(array[r]>b);
        if(l>=r){
            break;
        }
        swap(array[l] , array[r]);
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