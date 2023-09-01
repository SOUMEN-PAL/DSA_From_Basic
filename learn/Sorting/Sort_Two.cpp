#include<bits/stdc++.h>
using namespace std;


void CommonPartition(int arr[] , int n , bool (*Func)(int)){
    int i = -1  , j = n;
    while(true){
        do{
            i++;
        }while(Func(arr[i]));

        do{
            j--;
        }while(!Func(arr[j]));
        if(i>=j){
            return;
        }
        swap(arr[i] ,arr[j]);
    }
}

bool fun1(int n)
{
    if(n<0){
        return true;
    }
    return false;
}

bool fun2(int n){
    if(n%2!=0){
        return true;
    }
    return false;

}

bool fun3(int n){
    if(n==0){
        return true;
    }
    return false;
}

int main(){
    int Array1[] = {-2,4,-67,4,-8,4,6,7,8};
    int Array2[] = {1,4,7,9,7,3,4,5,6,8,10,34};
    int Array3[] = {1,0,1,0,1,0,1,1,1,1,0,0};
    int n1 = sizeof(Array1)/sizeof(Array1[0]);
    int n2 = sizeof(Array2)/sizeof(Array2[0]);
    int n3 = sizeof(Array3)/sizeof(Array3[0]);

    CommonPartition(Array1, n1 , fun1);
    CommonPartition(Array2 , n2 , fun2);
    CommonPartition(Array3 , n3 , fun3);

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