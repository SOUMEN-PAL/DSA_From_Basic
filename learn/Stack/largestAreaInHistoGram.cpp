#include<bits/stdc++.h>
using namespace std;


// Naive SOlution //
int largestAreaInHistogram(int arr[] , int n){
    int res = INT_MIN;

    for(int i = 0 ; i<n ; i++){
        int curr = arr[i];

        for(int j = i-1  ; j>=0 ; j--){
            if(arr[j]>=arr[i]){
                curr = curr + arr[i];
            }
            else{
                break;
            }
        }

        for(int j = i + 1 ; j<n ; j++){
            if(arr[j]>=arr[i]){
                curr = curr + arr[i];
            }
            else{
                break;
            }
        }

        res = max(res , curr);
    }
    return res;
}

// Better Solution O(n) : TC//
// we need the indices //
//_________________PreProcessing Functions________________//
vector<int> previousSmaller(int arr[] , int n){
    stack<int> s;
    vector<int> res;
    s.push(0);
    for(int i = 0 ; i<n ; i++){
        while(s.empty() == false && arr[s.top()]>=arr[i]){
            s.pop();
        }

        int ps = s.empty()?-1 : s.top();
        res.push_back(ps);
        s.push(i);
    }
    return res;

}

//_________________PreProcessing Functions________________//
vector<int> nextsmaller(int arr[] , int n){
    stack<int> s;
    vector<int> res;
    s.push(n-1);
    for(int i = n-1 ; i>=0 ; i--){
        while(s.empty() == false && arr[s.top()]>=arr[i]){
            s.pop();
        }

        int ns = s.empty() ? n : s.top();
        res.push_back(ns);
        s.push(i);// isko //
    }
    reverse(res.begin() , res.end());
    return res;
}

int largestAreaInHistogramBetter(int arr[] , int n){
    vector<int> ns = nextsmaller(arr , n);
    vector<int> ps = previousSmaller(arr , n);


    for(auto i : ns)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    int res = 0;
    for(int i = 0 ; i<n ; i++){
        int curr = arr[i];
        curr = curr + ((i - ps[i] - 1)*arr[i]);
        curr = curr + ((ns[i] - i - 1)*arr[i]);
        res = max(res , curr);
    }
    return res;
}


//______________________________________Efficient Solution______________________________________//
int LargestAreaHistogram(int arr[] , int n){
    stack<int> s;
    int res = 0;
    for(int i = 0 ; i<n ; i++){
        while(s.empty() == false && arr[s.top()]>=arr[i]){
            int tp = s.top();
            s.pop();
            int curr = arr[tp]*(s.empty()?i : (i - s.top() - 1));
            res = max(res , curr);
        }
        s.push(i);
    }

    while(s.empty() == false){
        int tp = s.top();
        s.pop();
        int curr = arr[tp]*(s.empty()?n : (n - s.top() - 1));
        res = max(res , curr);
    }
    return res;
}


int main(){
    int arr[] = {4,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<largestAreaInHistogram(arr , n)<<endl;
    cout<<largestAreaInHistogramBetter(arr , n)<<endl;
    cout<<LargestAreaHistogram(arr , n)<<endl;
    
    
    // vector<int> res = nextsmaller(arr , n);
    // for(auto i : res){
    //     cout<<i<<" ";
    // }
    
    return 0;
}