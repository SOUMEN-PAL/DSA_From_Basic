#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void insertt(int arr[] , int n , int x , int cap , int pos){
    if(n==cap){
        cout<<"Cant inset in the array"<<endl;
    }
    else{// else me dalo warna move kar dega aur age ke valyues ko size ke bahar kar dega //
        int index = pos - 1;
        for(int i = n-1 ; i>=index ; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = x;       
    }
}

int main(){
    int arr[5] = {1,34,21,5};
    int size = 4;
    int value = 24;
    int pos = 2;
    int capacity = 5;
    insertt(arr , size , value , capacity , pos);
    for(int i  = 0  ; i<5 ; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}