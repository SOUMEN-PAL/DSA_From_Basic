#include<bits/stdc++.h>
using namespace std;

vector<int> linearProbing(vector<int> arr , int arraySize , int HashSIze){
    vector<int> hash(HashSIze , -1);
    int insertCount = 0;
    for(int i = 0 ; i<arraySize ; i++){
        int num = arr[i];
        int index = num%HashSIze;
        int originalIndex = index;
        while(hash[index] != -1 && hash[index] != num){
            index = (index+1)%HashSIze;
            if(index == originalIndex){
                break;
            }
        }
        if(insertCount == HashSIze){
            break;
        }
        if(hash[index] == -1){
            hash[index] = num;
        }
    }
    return hash;
}


int main(){

    // implemented linear probing that avoids collision //
    
    return 0;
}