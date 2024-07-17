#include<bits/stdc++.h>
using namespace std;

struct myComp{
    bool operator()(int &a , int &b){
        return a<b;
    }
};

bool comp(int a , int b){
    return a<b;
}

int main(){
    int arr[] = {1,2,4};
    priority_queue<int , vector<int> , myComp> pq(arr , arr+3);
    cout<<"pq output: ";
    while (!pq.empty())
    {
        /* code */
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    cout<<"sort output: ";

    sort(arr , arr+3 , comp);
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;

    return 0;
}