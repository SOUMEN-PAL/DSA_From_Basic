#include<bits/stdc++.h>
using namespace std;

int countDistinct (int arr[], int n, int k)
{
    int res = INT_MIN;
    map<int , int> mp;
    for(int i = 0 ; i<k ; i++)
    {
        mp[arr[i]]++;
    }
    res = max(res , (int)mp.size());
    for(int i = k ; i<n ; i++)
    {
        mp[arr[i-k]] -= 1;
        if(mp[arr[i-k]] == 0)
        {
            mp.erase(arr[i-k]);
        }
        mp[arr[i]]++;
        res = max(res , (int)mp.size());
    }
    return res;
}


int main(){
    int arr[] = {1,2,2,3,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<countDistinct(arr , n , k);
    
    return 0;
}