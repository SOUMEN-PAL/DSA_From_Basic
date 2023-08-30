#include<bits/stdc++.h>
using namespace std;


int Hoores_partition(int arr[] , int l , int h){
    int pivot = arr[h];
    int i = l-1 , j = h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);

        do
        {
            j--;
        } while (arr[j]>pivot);
        
        if(i>=j)
        {
            return i;
        }
        swap(arr[i] , arr[j]);
    }
}



int main(){

    int arr[] = {5,3,1,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = Hoores_partition(arr , 0 , n-1);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<x<<endl;
    

    return 0;
}