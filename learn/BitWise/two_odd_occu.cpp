#include <bits/stdc++.h>
using namespace std;
// naive solution //
void two_odd_one(int arr[],int n){
    for(int i = 0 ; i<n ;i++){
        int count=0;
        for(int j = 0 ; j<n ; j++){
            if(arr[i]==arr[j]){
                count++;
            } // this solution will gonna print all the times the odd ones are appearing //
            // so it not locking good //
        }
        if(count%2!=0){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

// efficient solution //
void twoodd(int arr[] , int n){
    int x=arr[0];
    for(int i=1 ; i<n ; i++){
        x=x^arr[i];
    }
    int k = (x & (~(x-1))); // or use 1<<floor(log2(x));//
    int One_Ans=0 , Second_Ans=0;
    for(int i = 0 ; i<n ; i++){
        if((arr[i]&k)!=0){
            One_Ans=One_Ans ^ arr[i]; // differentiated the set bits //
        }
        else{
            Second_Ans= Second_Ans ^ arr[i]; // differentiated the unset bits //
        }

    }
    if(One_Ans==0 && Second_Ans==0){
        cout<<-1<<endl;
    }
    else{
        cout<<"The two odd occuring numbers are: "<<One_Ans<<" "<<Second_Ans<<endl;
    }
   


} 


int main(){
    
    int arr[]={1,1,1,1,2,2,2,2,4,4,4,10,10,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    two_odd_one(arr,n);
    twoodd(arr,n);

    return 0;
}