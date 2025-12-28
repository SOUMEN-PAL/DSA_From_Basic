#include<bits/stdc++.h>
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