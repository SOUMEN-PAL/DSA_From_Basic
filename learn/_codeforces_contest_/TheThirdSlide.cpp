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
typedef long long ll;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    
    
    while(t--){
        
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
        }
        
        sort(arr.begin() , arr.end());
        
        
        if(n == 1){
            cout<<arr[0]<<endl;
        }
        else{
            int sum = arr[0];
            
            for(int i = 1 ; i<n ; i++){
                sum = (sum + arr[i])%mod;
                sum = (sum - 1)%mod;
            }
            cout<<sum<<endl;
        }
        
        
        
    }
    
    
    return 0;
}