#include <iostream>
using namespace std;

void fun(int arr[]){
    cout<<sizeof(arr)/sizeof(arr[0]);
}

int main(){
    int arr[] = {1,2,3,4,5};
    fun(arr);

    return 0;
}