#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;

        int maxArea = n*(m*m);

        pair<pair<int , int> , pair<int , int>> p;

        p.first.first = 0;
        p.first.second = 0;
        p.second.first = m;
        p.second.second = m;

        vector<pair<pair<int , int> , pair<int , int>>> v;

        for(int i = 0 ; i<n ; i++){
            int offsetX , offsetY;
            cin>>offsetX>>offsetY;

            p.first.first += offsetX;
            p.first.second += offsetY;
            p.second.first += offsetX;
            p.second.second += offsetY;

            v.push_back(p);
        }

        int removedArea = 0;
        int totalPerimeter = 4*m*n;

        for(int i = 1 ; i<v.size() ; i++){
            
 

            int shapePerimeter = 2*(abs(v[i].first.first - v[i-1].second.first) + abs(v[i].first.second - v[i-1].second.second));

            totalPerimeter -= shapePerimeter;
        }


        cout<<totalPerimeter<<endl;

    }
    return 0;
}