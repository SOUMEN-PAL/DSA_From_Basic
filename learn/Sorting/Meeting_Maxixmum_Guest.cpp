#include<bits/stdc++.h>
using namespace std;


// My naive solution not working thought about merging the slots and counting it //
bool myComp(pair<int , int> &a , pair<int , int> &b){
    return a.first < b.first;
}

int Maximum_Guest(int arr[], int dep[] , int n){
    vector<pair<int , int>> Array;
    for(int i = 0 ; i<n  ; i++){
        Array.push_back(make_pair(arr[i] , dep[i]));
    }
    sort(Array.begin() , Array.end() , myComp);
    for(auto i : Array){
        cout<<i.first<<" "<<i.second<<endl;
    }
    int res = 0 , count = 1;
    for(int i = 1 ; i<n ; i++){
        if(Array[i].first<=Array[res].second){
            Array[res].first = min(Array[i].first , Array[res].first);
            Array[res].second = max(Array[i].second , Array[res].second);
            count++;
        }
        else{
            res++;
            Array[res] = Array[i];
        }
    }
    cout<<"MErged"<<endl;
    for(int i = 0 ; i<=res ; i++){
        
        cout<<Array[i].first<<" "<<Array[i].second<<endl;
    }
    
    return count;
}


// Efficient Solution //
int max_guest(int arr[] , int dep[] , int n){
    sort(arr , arr+n);
    sort(dep , dep+n);
    int i = 1 , j = 0 , res = INT_MIN , curr = 1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }
        res = max(res , curr);
    }
    return res;
}

int main(){
    int arr[] = {900,940,950,1100,1500,1800};
    int brr[] = {910,1200,1120,1130,1900,2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<max_guest(arr , brr , n)<<endl;
    
    return 0;
}