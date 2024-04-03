#include<bits/stdc++.h>
using namespace std;


// Efficient bruteForce Approach O(n)//
int CircularTour(int petrol[] , int distance[] , int n){
    int start = 0;
    int extra_fuel = 0;
    int required_fuel = 0;
    for(int i = 0 ; i<n ; i++){
        extra_fuel += petrol[i] - distance[i];
        if(extra_fuel<0){
            start = i+1;
            required_fuel += extra_fuel;
            extra_fuel = 0;
        }
    }
    if(required_fuel + extra_fuel >= 0){
        return start+1; // 1 based indexing //
    }
    return -1;
}


// Queue based Solution //
int tour(vector<pair<int, int>> petrolPumps, int n)
{
    deque<int> dq;
    int curr_petrol = 0;
    int i = 0;
    while (dq.size() != n)
    {
        curr_petrol += petrolPumps[i].first - petrolPumps[i].second;
        dq.push_back(i);
        i = (i + 1) % n;
        while (!dq.empty() && curr_petrol < 0)
        {
            int removed = dq.front();
            dq.pop_front();
            curr_petrol -= petrolPumps[removed].first - petrolPumps[removed].second;
        }
    }
    if (curr_petrol < 0)
        return -1;
    else
        return dq.front();
}


int main(){
    int p[] = {4,8,7,4};
    int d[] = {6,5,3,5};
    int n = sizeof(p)/sizeof(p[0]);
    cout<<CircularTour(p , d , n)<<endl;
    
    return 0;
}