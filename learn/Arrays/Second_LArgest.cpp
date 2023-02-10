#include <bits/stdc++.h>
using namespace std;


// naive solution //

int largest(int arr[] , int n){
    int temp_Index = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]>arr[temp_Index]){
            temp_Index = i;
        }
        else{
            temp_Index = temp_Index;
        }
    }
    return temp_Index;
}

int second_largest(int arr[] , int n){
    int Largest_ele = largest(arr , n);
    int res = -1;
    for(int i = 0  ; i<n ; i++){
        if(arr[i]!=arr[Largest_ele]){
            if(res==-1){
                res = i;
            }
            else if(arr[i]>arr[res]){
                res = i;
            }
        }
    }
    return arr[res]; 
}


// efficient solution //

vector<int> ans; 
void s_lar(int arr[] , int n){
    int sec = -1 , large = 0;
    for(int j = 1 ; j<n ; j++ ){
        if(arr[j]>arr[large]){
            sec = large;
            large = j;
        }
        else if(arr[j] != arr[large]){
            if(sec == -1 || arr[j]>arr[sec]){
                sec = j;
            }
        }
    }

    ans.push_back(arr[large]);
    ans.push_back(arr[sec]);


}




int main(){
    int arr[] = {10,101,101};
    int n  = sizeof(arr)/sizeof(arr[0]);
    cout<<second_largest(arr , n)<<endl;;
    s_lar(arr , n);
    for(int i = 0 ; i<2 ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
      


    return 0;
}