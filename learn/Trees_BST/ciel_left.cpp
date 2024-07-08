#include<bits/stdc++.h>
using namespace std;

void printCeiling(int arr[] , int n){
    cout<<-1<<" ";
    set<int> s;
    s.insert(arr[0]);
    for(int i = 1 ; i<n ; i++){
        if(s.lower_bound(arr[i]) != s.end()){
            cout<<*(s.lower_bound(arr[i]))<<" ";
        }
        else
            cout<<"-1"<<" ";
        s.insert(arr[i]);
    }
}

int main(){
    	
	int arr[]={10,6,9,7,20,19,21,18,17,16};
	int n=sizeof(arr)/sizeof(arr[0]);

	
	printCeiling(arr,n);
    cout<<endl;

    set<int> s(arr , arr+n);

    


    return 0;
}