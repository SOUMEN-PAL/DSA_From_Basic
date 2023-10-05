#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> separateChaining(int hashSize,int arr[],int sizeOfArray)
{
   vector<vector<int>> res(hashSize);
   for(int i = 0 ; i<sizeOfArray ; i++){
       int index = arr[i]%hashSize;
       res[index].push_back(arr[i]);
   }
   return res;
}
    



int main(){
    int hashSize = 10, sizeOfArray = 6, arr[] = {92,4,14,24,44,91};
    vector<vector<int>> res = separateChaining(hashSize , arr , sizeOfArray);
    for(auto i : res){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}