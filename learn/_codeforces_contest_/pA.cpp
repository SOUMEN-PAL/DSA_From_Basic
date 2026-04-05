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


int mex(vector<int>& triplet) {
    set<int> s(triplet.begin(), triplet.end());
    int mex_value = 0;
    while (s.count(mex_value)) {
        mex_value++;
    }
    return mex_value;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        set<int>st;
        
        for(int i = 0 ; i<n ; i++){
            int a;
            cin>>a;
            st.insert(a);
        }
        
        std::set<int>::iterator it = st.begin();
        std::set<int>::iterator jt = st.end();
        // Dereference the iterator to get the value
        int min = *it;
        int max = *jt;
    
        
        
        
    }
    
    return 0;
}