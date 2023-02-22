#include <bits/stdc++.h>
using namespace std;


// naive solution //
void rotate(int arr[], int n , int j)
{
    int temp = arr[n-1];
    for(int i = n-1 ; i>j ; i--){
        arr[i] = arr[i-1];
    }
    arr[j] = temp;
}



void alter(int arr[] , int n){
    for(int i = 0 ; i<n ; i=i+2){
        rotate(arr , n , i);
    }
}
// TC: O(n^2)
// AS : O(1);


// efficinet solution //

void rearr(int arr[] , int n){
    int max = n-1; // two pointers approach //
    int min = 0;
    int max_ele = arr[n-1]+1;
    for(int i = 0 ; i<n ; i++){
        if(i%2==0){
            arr[i] = arr[i] + (arr[max]%max_ele)*max_ele;
            max--;
        }
        else{
            arr[i] = arr[i] + (arr[min]%max_ele)*max_ele;
            min++;
        }
    }

    for(int i = 0 ; i<n ; i++){
        arr[i] = arr[i]/max_ele;
    }

}

// TC : O(n);
// AS : O(1);


int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    rearr(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}