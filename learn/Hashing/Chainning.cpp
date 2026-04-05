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