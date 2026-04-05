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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        long long k; 
        cin >> k; 
    
      
        long long current = -1e18;
        bool possible = true;
        for (int i = 0; i < n; i++){
        
            long long option0 = a[i];
            long long option1 = k - a[i];
            
            long long candidate = 1e18; 
            if(option0 >= current) candidate = min(candidate, option0);
            if(option1 >= current) candidate = min(candidate, option1);
            
            if(candidate == 1e18){ 
                possible = false;
                break;
            }
            current = candidate; 
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
