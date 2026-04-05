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

vector<int> helper(int arr[] , int n){
    
}


int main()
 {
	int n;
	cin>>n;
	while(n--){
	    int c;
	    cin>>c;
	    int arr[c];
	    for(int i = 0 ; i<c ; i++){
	        cin>>arr[i];
	    }
	
	
	
	    set<int> s;
	    s.insert(arr[c-1]);
	    int res = 0;
	    for(int i = c-2 ; i>=0 ; i--){
	        auto pos = s.lower_bound(arr[i]);
	        
	        int dis = distance(s.begin() , pos);
	        res = max(res , dis);
	        s.insert(arr[i]);
	    }
	    
	    cout<<res<<endl;
	
	
	}
	

	
	return 0;
}