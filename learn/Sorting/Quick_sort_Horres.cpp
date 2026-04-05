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

int partition(int arr[], int l, int h)
{
    

    int pivot = arr[l];
    int i = l-1 , j = h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j){return j;}
        swap(arr[i] , arr[j]);
    }
}


void Q_sort(int arr[], int low, int high) {
    if (low < high)
    {
        int p = partition(arr, low, high);
        
        Q_sort(arr, low, p);
        Q_sort(arr, p+1, high);
    }
}

/*
tail recurssive quick sort
void Q_sort(int arr[], int low, int high) {
    begin:
    if (low < high)
    {
        int p = partition(arr, low, high);
        
        Q_sort(arr, low, p);
        low = p+1;
        goto begin;
    }
}
*/


int main() {
    int arr[] = {1,6,3,2,58,5,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Q_sort(arr , 0 , n-1);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}