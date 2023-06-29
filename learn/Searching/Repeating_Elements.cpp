#include<bits/stdc++.h>
using namespace std;

// super naive solution //
int Repeat_solution(vector<int> arr){
    int n = arr.size();
    for(int i = 0 ;  i<n ; i++){
        for(int j = i+1 ; j< n  ; j++){
            if(arr[i] == arr[j]){
                return arr[i];
            }
        }
    }

    return INT_MAX;
}

// naive solution //
int Repeat_ele(vector<int> arr){
    int n = arr.size();
    sort(arr.begin() , arr.end());
    for(int i = 1 ; i< n ; i++){
        if(arr[i] == arr[i-1]){
            return arr[i];
        }
    }
    return INT_MAX;
}

// Efficient SOlution  O(n) solution O(n) space//

int Repeated_ELement(vector<int> arr){
    int n = arr.size();
    vector<bool> ved(n , false);
    for(int i = 0  ; i,n ; i++){
        if(ved[arr[i]]==true){
            return arr[i];
        }
        ved[arr[i]] = true;
    }

    return -1;
}





int main(){
    vector<int> arr = {1,2,4,5,6,6,7,8};
    cout<<Repeat_solution(arr)<<" "<<Repeat_ele(arr)<<" "<<Repeated_ELement(arr);
    return 0;
}