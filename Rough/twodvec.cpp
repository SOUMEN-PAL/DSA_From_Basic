#include <bits/stdc++.h>
using namespace std;





int main(){
    vector<vector<int>> a;
    vector <int> b;
    b.push_back(1);
    a.push_back(b);
// we are not able to directly push back in a 2d array so as there is a vector in a vector so its bette to make a vector andd push back it to a another array which a 2d array//
    cout<<a[0][0];   


    return 0;
}