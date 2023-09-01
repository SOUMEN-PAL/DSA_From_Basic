#include<bits/stdc++.h>
using namespace std;

// seperate positive and negative element //

void seg_array(int arr[] , int n){
    int low = -1 , high = n;
    while(true){
        do{
            low++;
        }while(arr[low]<0);

        do{
            high--;
        }while(arr[high]>=0);
        if(low>=high){
            return; // to break the loop //
        }
        swap(arr[low] , arr[high]);
    }
}

// seperate odd and even elements //

void Seperate_Odd_and_Even(int arr[] , int n){
    int i = -1 , j = n;
    while(true){
        do{
            i++;
        }while(arr[i]%2 != 0);

        do{
            j--;
        }while(arr[j] % 2 == 0);

        if(i>=j){
            return;
        }

        swap(arr[i] ,arr[j]);
    }
}


// seperate 0s and 1s in the array //

void Seperate_ones_and_Zeroes(int arr[] , int n){
    int i = -1 , j = n;
    while(true){
        do{
            i++;
        }while(arr[i] == 0);

        do{
            j--;
        }while(arr[j] == 1);

        if(i>=j){
            return;
        }
        swap(arr[i] , arr[j]);
    }
}

// or could have used a variation of move 0 to end //


int main(){
    int Array1[] = {-2,4,-67,4,-8,4,6,7,8};
    int Array2[] = {1,4,7,9,7,3,4,5,6,8,10,34};
    int Array3[] = {1,0,1,0,1,0,1,1,1,1,0,0};
    int n1 = sizeof(Array1)/sizeof(Array1[0]);
    int n2 = sizeof(Array2)/sizeof(Array2[0]);
    int n3 = sizeof(Array3)/sizeof(Array3[0]);
    seg_array(Array1 , n1);
    Seperate_Odd_and_Even(Array2 , n2);
    Seperate_ones_and_Zeroes(Array3 , n3);

    for(int i = 0 ; i<n1 ; i++){
        cout<<Array1[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i<n2 ; i++){
        cout<<Array2[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i<n3 ; i++){
        cout<<Array3[i]<<" ";
    }
    cout<<endl;
    return 0;
}