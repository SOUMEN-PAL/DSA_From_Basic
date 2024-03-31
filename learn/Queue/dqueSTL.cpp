#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq = {1,2,3,4,5};
    dq.push_front(20);

    auto it = dq.begin();
    dq.insert( it , 90);

    cout<<dq.front();

    dq.pop_front();
    

    return 0;
}