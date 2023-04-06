#include<bits/stdc++.h>
using namespace std;


vector <string> v = {"" , ""  , "ABC" , "DEF" , "GHI" , "JKL" , "MNO" , "PQRS" , "TUV" , "WXYZ"};

void ph(int arr[] , int n , string s = "" , int i = 0){
    if(i==n){
        cout<<s<<" ";
        return;
    }
    else{
        for(int j = 0 ; j<v[arr[i]].size() ; j++){
            ph(arr , n , s+v[arr[i]][j] , i+1);
        }
    }


}




int main(){
    int arr[] = {2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    ph(arr , n);

    return 0;
}