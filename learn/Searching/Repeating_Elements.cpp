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
// most Efficient Solution//

int Repeated_element(int arr[] , int n){
    int slow = arr[0]+1 , fast = arr[0]+1;
    do{
        slow = arr[slow]+1;
        fast = arr[arr[fast]+1]+1;
    }while(slow != fast);

    slow = arr[0]+1;
    while(slow != fast){
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }

    return slow-1;
}







int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,7};
    cout<<Repeat_solution(arr)<<" "<<Repeat_ele(arr)<<" "<<Repeated_ELement(arr)<<endl;
    int arr1[] = {0,1,2,3,4,5,6,7,7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<Repeated_element(arr1 , n)<<endl;
    return 0;
}