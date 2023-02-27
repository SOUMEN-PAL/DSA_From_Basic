#include <bits/stdc++.h>
using namespace std;
/*
        //-------- My approach --------//

void fre(int arr[] , int n , int p){
    sort(arr , arr+n);
    int d = 0;
    for(int i = 1 ; i<=p ; i++){
        int c = 0;
        for(int j = 0 ; j<n ; j++){
            if(arr[j]%(n+1)==i){
                c++;
            }
        }
  
        arr[i-1] = arr[i-1] + c*(n+1);
    }

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]/(n+1)<<" ";
    }
}


no mater whats the value of p we have to check for upto N no mater whats the value int the array we have to count the no of 
times the elements are and modify the array

*/

//------------ Brute Force appraoch -------------//
// void fr(int arr[] , int n ){
//     int ans[n];
//     for(int i = 1 ; i<=n ; i++){
//         int c = 0;
//         for(int j = 0 ; j<n ; j++){
 
//             if(arr[j]==i){
//                 c++;
//             }
            
//         }
//         ans[i-1] = c;
//     }
//     for(int i = 0 ; i<n ; i++){
//         arr[i] = ans[i];
//     }
//     cout<<endl;
// }

// efficient solution //
void fre(int arr[] , int n){
    map<int , int> ans;
    for(int i = 1 ; i<=n ; i++){
        ans[i] = 0;
    }
    map<int,int> :: iterator it ;
    
    int i = 0;
    for(int i = 0 ; i<n ; i++){
        ans[arr[i]]++;
    }
    for(it= ans.begin() ; it!=ans.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    for(int i = 0  ; i<n ; i++){
        arr[i] = ans[i+1];
    }

    cout<<"Value of arrays"<<endl;
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    


}


int main(){
    int arr[] = {2,3,2,7,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    fre(arr , n);





    return 0;
}