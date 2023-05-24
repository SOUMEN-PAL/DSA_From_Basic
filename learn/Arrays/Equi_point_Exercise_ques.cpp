#include<bits/stdc++.h>
using namespace std;

bool Eq_sum(int arr[] , int n){
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum = sum+arr[i];
    }

    if(sum%3!=0){
        return false;
    }

    int curr_sum = 0;
    int par_count = 0;
    int tag_sum = sum/3;


    for(int i = 0 ; i<n ; i++){
        curr_sum = curr_sum + arr[i];

        if(curr_sum == tag_sum){
            curr_sum = 0;
            par_count++;
        }


        if(par_count==3){
            return true;
        }
    


    }

    return false;

    



}



int main(){


    int arr[] = {5,2,6,1,1,1,4};

    int n = sizeof(arr)/sizeof(arr[0]);

    if(Eq_sum(arr , n)){
        cout<<"Yes exist"<<endl;
    }
    else{
        cout<<"Does not exist"<<endl;
    }
    
    return 0;
}