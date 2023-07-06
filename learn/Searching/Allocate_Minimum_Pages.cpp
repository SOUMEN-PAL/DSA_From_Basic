#include<bits/stdc++.h>
using namespace std;


//______________________NAive SOlution___________________//

int sum(int arr[],int b, int e){
    int s=0;
    for(int i=b;i<=e;i++)
        s+=arr[i];
    return s;
}

int minPages(int arr[] , int n  , int k){
    
    if(k==1){
        return sum(arr , 0 , n-1);
    }
    if(n==1){
        return arr[0];
    }
    int res = INT_MAX;
    for(int i = 1 ; i<n ; i++){
        res = min(res , max(minPages(arr , i , k-1) , sum(arr , i , n-1)));
    }
    return res;
}

//______________________Efficient SOlution________________________//

bool isFesiable(int arr[] , int n , int k , int ele){
    int sum = 0;
    int students = 1;
    for(int i  = 0 ; i<n ; i++){
        int curr = arr[i]+sum;
        if(curr>ele){
            students++;
            sum = arr[i];
        }
        else{
            sum += arr[i];
        }
    }

    if(students>k){
        return false;
    }
    return true;
}

int Minimum_Pages(int arr[] , int n , int k){
    int arrSum = 0 , maxInArr = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        arrSum += arr[i];
        maxInArr = max(maxInArr , arr[i]);
    }
    int low = maxInArr , high = arrSum, res = 0;
    while(high>=low){
        int mid = (high + low)/2;
        if(isFesiable(arr , n , k , mid)){
            high = mid - 1;
            res = mid;
        }
        else{
            low = mid+1;
        }
    }
    return res;
}





int main(){
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<minPages(arr , n , k)<<endl;
    cout<<Minimum_Pages(arr , n , k)<<endl;
    return 0;
}