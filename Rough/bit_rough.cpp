#include <iostream>
using namespace std;

int maxAND (int arr[], int N)
{
    // Your code here
    int p =0;
    int value=0;
    while(p<N){
        for(int i = p+1 ; i<N ; i++){ // its an naive solution we need an efficient solution witj O(N) and it (N^2) //
            int m=arr[p];
            int n=arr[i];
            int k =m&n;
            if(k>value){
                value=k;
            }
        }
        p++;
    }
    return value;
    
}

int main(){
    int a[]={4,8,12,16};
    cout<<maxAND(a,4);


    
    return 0;
}