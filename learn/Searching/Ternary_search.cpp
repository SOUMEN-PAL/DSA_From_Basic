#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int l, int r, int key, int ar[]) 
{ 
    if (r >= l) 
    { 
        // Find mid1 and mid2 
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
  
        // Check if key is present at any mid 
        if (ar[mid1] == key)  
        { 
            return mid1; 
        } 
        if (ar[mid2] == key) 
        { 
            return mid2; 
        } 
  
        // Since key is not present at mid, 
        // check in which region it is present 
        // then repeat the Search operation 
        // in that region 
        if (key < ar[mid1])  
        { 
  
            // The key lies in between l and mid1 
            return ternarySearch(l, mid1 - 1, key, ar); 
        } 
        else if (key > ar[mid2])  
        { 
  
            // The key lies in between mid2 and r 
            return ternarySearch(mid2 + 1, r, key, ar); 
        } 
        else
        { 
  
            // The key lies in between mid1 and mid2 
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar); 
        } 
    } 
  
    // Key not found 
    return -1; 
} 



int main(){


    int arr[] = {1,2,3,4,5,6,7,8,99,100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<ternarySearch(0 , n-1 , 91 , arr)<<endl;
    
    return 0;
}