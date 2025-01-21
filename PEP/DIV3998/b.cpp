#include <bits/stdc++.h>
using namespace std;

// Comparator for priority queue
struct comp {
    bool operator()(pair<int, priority_queue<int, vector<int>, greater<int>>> &a,
                    pair<int, priority_queue<int, vector<int>, greater<int>>> &b) {
        if (a.second.empty()) return true;  // Empty queues should come after non-empty ones
        if (b.second.empty()) return false;
        return a.second.top() > b.second.top();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        priority_queue<
            pair<int, priority_queue<int, vector<int>, greater<int>>>,
            vector<pair<int, priority_queue<int, vector<int>, greater<int>>>>,
            comp>
            pq;

        for (int i = 0; i < n; i++) {
            priority_queue<int, vector<int>, greater<int>> pqTemp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                pqTemp.push(x);
            }
            pair<int, priority_queue<int, vector<int>, greater<int>>> p = {i, pqTemp};
            pq.push(p);
        }

        vector<int> res;
        bool possible = true;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if (curr.second.empty()) continue;  // Skip empty queues

            res.push_back(curr.first);

            // Check the next element
            if (!pq.empty() && !pq.top().second.empty() &&
                pq.top().second.top() == curr.second.top() + 1) {
                curr.second.pop();
                pq.push(curr);
            } else {
                possible = false;
                break;
            }
        }

        bool valid = true;

        unordered_set<int> seen;
        for(int i = 0 ; i<n ; i++){
            if(seen.find(res[i]) != seen.end()){
                cout<<-1<<endl;
                valid = false;
                break;
            }
            seen.insert(res[i]);
        }

        for(int i = 0; i<n ; i++){
            int j = i;
            while(j<(m*n) - n){
                if(res[j] != res[j+n]){
                    cout<<-1<<endl;
                    valid = false;
                    break;
                }
                j+=n;
            }
        }
        
        if(valid){
            for(int i = 0 ; i<n ; i++){
                cout<<res[i]+1<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}





// #include<bits/stdc++.h>
// using namespace std;

// //comparater for priority queue
// struct comp {
//     bool operator()(pair<int, priority_queue<int, vector<int>, greater<int>>> &a,
//                     pair<int, priority_queue<int, vector<int>, greater<int>>> &b) {
//         if (a.second.empty()) return true;  // Empty queues should come after non-empty ones
//         if (b.second.empty()) return false;
//         return a.second.top() > b.second.top();
//     }
// };



// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n , m;
//         cin>>n>>m;
        
        
//         priority_queue<pair<int, priority_queue<int, vector<int>, greater<int>>> , vector<pair<int, priority_queue<int, vector<int>, greater<int>>>> , comp> pq;

//         for(int i = 0 ; i<n ; i++){
//             priority_queue<int, vector<int>, greater<int>> pqTemp;
//             for(int j = 0 ; j <m ; j++){
//                 int x;
//                 cin>>x;
//                 pqTemp.push(x);
//             }
//             pair<int, priority_queue<int, vector<int>, greater<int>>> p = {i , pqTemp};
//             pq.push(p);

//         }


//         // //print the content of pq
//         // while(!pq.empty()){
//         //     auto curr = pq.top();
//         //     cout<<curr.first<<" ";
//         //     while(!curr.second.empty()){
//         //         cout<<curr.second.top()<<" ";
//         //         curr.second.pop();
//         //     }
//         //     cout<<endl;
//         //     pq.pop();
//         // }

//         vector<int> res;
//         bool possible = true;
//         while(!pq.empty()){
//             auto curr = pq.top();
//             if(curr.second.empty()){
//                 pq.pop();
//                 continue;
//             }
//             res.push_back(curr.first);
//             pq.pop();
//             if(pq.top().second.top() == curr.second.top()+1){
//                 curr.second.pop();
//                 pq.push(curr);
                
//             }
//             else{
//                 possible = false;
//                 break;
//             }
//         }

//         if(possible && res.size() == n){
//             for(auto x : res){
//                 cout<<x+1<<" ";
//             }
//             cout<<endl;
//         }
//         else{
//             cout<<-1<<endl;
//         }

//     }
//     return 0;
// }