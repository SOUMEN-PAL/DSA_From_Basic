#include<bits/stdc++.h>
using namespace std;


// naive solution //
int longest(int arr[] , int n){
    int res = 1;
    for(int i = 0 ; i<n ; i++){
        int curr =1;
        for(int j = i+1 ; j<n ; j++){
            if((arr[j]%2==0 && arr[j-1]%2!=0) || (arr[j]%2!=0 && arr[j-1]%2==0)){
                curr++;

            }
            else{
                break;
            }

        }
        res = max(res , curr);
    }
    return res;

}

// eff solutioin my way //

int longg(int arr[] , int n){
    int curr = 1 , res = 1;
    for(int i = 1 ; i<n ; i++){
        if((arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i]%2!=0 && arr[i-1]%2==0)){
            
            curr++;

        }
        else{
            res = max(res , curr);
            curr = 1;
            
        }
    }
    res = max(res , curr);

    return res;
}

// eff solution GFG //

int maxoddeven(int arr[] , int n){
    int res = 1 ; int curr = 1;

    for(int i = 1 ; i<n ; i++){
        if((arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i]%2!=0 && arr[i-1]%2==0)){
            curr++;
            res = max(res , curr);
        }
        else{
            curr=1;
        }
    }
    return res;
}


int main(){
    int arr[] = {8,6,7,8,9,1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longest(arr , n)<<endl;
    cout<<longg(arr , n)<<endl;
    cout<<maxoddeven(arr , n)<<endl;
    
    return 0;
}