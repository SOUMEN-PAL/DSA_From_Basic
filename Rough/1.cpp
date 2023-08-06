#include <iostream>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    // code here 
    long long int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum += arr1[i];
    }
    for(int i = 0 ; i<m ; i++){
        sum += arr2[i];
    }
    
    
    
    long long int i = 0 , j = 0 , ind1 = 0 , ind2 = 0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            if(ind1 != n){
                arr1[ind1] = arr1[i] + (arr1[ind1]/sum)*sum;
                i++;
                ind1++;
            }
            else{
                arr2[ind2] = arr2[i] + (arr2[ind2]/sum)*sum;
                i++;
                ind2++;
            }
        }
        else{
            if(ind1 != n){
                arr1[ind1] = arr1[j] + (arr1[ind1]/sum)*sum;
                j++;
                ind1++;
            }
            else{
                arr2[ind2] = arr2[j] + (arr2[ind2]/sum)*sum;
                j++;
                ind2++;
            }
        }
    }
    for(int i = 0 ; i<n ; i++){
        arr1[i] %= sum;
    }
    for(int i = 0 ; i<m ; i++){
        arr2[i] %= sum;
    }
    
} 

int main(){
    long long int arr1[] = {1 ,3 ,5 ,7};
    long long int arr2[] = {0 ,2 ,6 ,8 ,9};
    merge(arr1 , arr2 , 4 , 5);
    for(int i : arr1){
        cout<<i<<" ";
    }
    for(int i:arr2){
        cout<<i<<" ";
    }



}