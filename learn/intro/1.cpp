#include <iostream>
using namespace std;
int temp;


void search(int arr[],int n,int x){
    for(int i=0 ; i<n ; i++){
        if(x==arr[i]){
            cout<<x<<" is present on: "<<i<<" position."<<endl;
        }
        else{
            temp+=1;
        }

        if(temp==n){
            cout<<x<<" is not present in the array."<<endl;
        }
        
    }
    
    
}

int main(){
    int arr[]={2,9,24,12,34,56,78,12,34};
    int x=12;
    int n=sizeof(arr)/sizeof(arr[0]);
    search(arr,n,x);
    
    return 0;
}