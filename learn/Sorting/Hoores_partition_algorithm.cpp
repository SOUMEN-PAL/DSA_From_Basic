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


int Hoores_partition(int arr[] , int l , int h){
    int pivot = arr[h];
    int i = l-1 , j = h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);

        do
        {
            j--;
        } while (arr[j]>pivot);
        
        if(i>=j)
        {
            return i;
        }
        swap(arr[i] , arr[j]);
    }
}



int main(){

    int arr[] = {5,3,1,2,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = Hoores_partition(arr , 0 , n-1);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<x<<endl;
    

    return 0;
}