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