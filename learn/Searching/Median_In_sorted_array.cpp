#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


// naive solution //
float Median_sorted(vector<int> a1 , vector<int> a2){
    vector<int>res(a1);
    copy(a2.begin() , a2.end() , back_inserter(res));
    sort(res.begin() , res.end());
    int Size = res.size();
    if(Size%2==0){
        return float(res[Size/2] + res[( Size/2) - 1])/2;
    }
    else{
        return (float)res[Size/2];
    }
}

// Efficient Solution //
float median_Sorted(vector<int> v1 , vector<int> v2){
    int n1 = v1.size();
    int n2 = v2.size();
    if(n1>n2){
        return Median_sorted(v2 , v1);
    }
    int low = 0 , high = n1;
    int Real_mid = (n1 + n2 + 1)/2;
    while(low<=high){
        int mid1 = (high + low)/2;
        int mid2 = Real_mid - mid1;

        int min1 = (mid1<n1)?v1[mid1]:INT_MAX;
        int max1 = (mid1>0)?v1[mid1-1]:INT_MIN;

        int min2 = (mid2<n2)?v2[mid2]:INT_MAX;
        int max2 = (mid2>0)?v2[mid2-1]:INT_MIN;
        
        if(max1<=min2 && max2<=min1){
            if((n1 + n2) % 2==0){
                return (max(max1 , max2) + min(min1 , min2)) / 2.0;
            }
            else{
                return max(max1 , max2);
            }
        }
        else if(max1>min2){
            high  = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0.0;
}


int main(){
    vector<int> a1 = {10 , 20 , 40 , 50};
    vector<int> a2 = {2,4,6,8,10};
    cout<<Median_sorted(a1 , a2)<<endl;
    cout<<median_Sorted(a1 , a2)<<endl;

    return 0;
}