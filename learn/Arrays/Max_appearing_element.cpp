#include<bits/stdc++.h>
#define maxx 100
using namespace std;
// maximum most appearing element //
int max_in_rnage(int l[] , int r[] , int n){

    vector <int> fre(maxx , 0);
    for(int i = 0 ; i<n  ;i++){
        fre[l[i]]+=1;
        fre[r[i]+1]-= 1;
    }
    for(int i = 1 ; i <=maxx ; i++){
        fre[i] = fre[i]+fre[i-1];
    }
    
    int res = 0;
    for(int i = maxx-1 ; i>=1 ; i--){
        if(fre[i]>fre[res]){
            res = i;
        }
    }
    cout<<"The maximum appearing elements are: ";
    for(int i = 0 ; i<maxx ; i++){
        if(i!=res && fre[i]==fre[res]){
            cout<<i<<" ";
        }
    }

    return res;

}



int main(){

    int l[] = {1,2,1,1};
    int r[] = {4,5,6,7};
    int n = sizeof(l)/sizeof(l[0]);

    cout<<max_in_rnage(l , r , n)<<endl;
    
    return 0;
}