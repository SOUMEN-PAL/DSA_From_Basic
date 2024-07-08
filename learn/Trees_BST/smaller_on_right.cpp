#include <bits/stdc++.h>
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