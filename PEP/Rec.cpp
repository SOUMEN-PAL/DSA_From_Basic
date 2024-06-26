#include<bits/stdc++.h>
using namespace std;

// Print increasing with recusrrion
void printInc(int n){
    if(n==0){
        return;
    }
    printInc(n-1);
    cout<<n<<endl;
}
//Print Decreasing with recursion
void printDec(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    printDec(n-1);
}

// Print inc dec with recursion
void printIncDec(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    printIncDec(n-1);
    cout<<n<<endl;
}



// find element in a vector and return index
int contain(vector<int> arr , int target){
    if(arr.size()==0){
        return -1;
    }
    if(arr[0]==target){
        return 0;
    }
    int ans = contain(vector<int>(arr.begin()+1,arr.end()),target);
    if(ans==-1){
        return -1;
    }
    return ans+1;


}

// all indices of a target
vector<int> allIndx(vector<int> &arr , int target , int indx){
    static vector<int> res;
    if(indx == arr.size()){
        res.push_back(-1);
        return res;
    }

    if(arr[indx]==target){
        res.push_back(indx);
    }
    allIndx(arr,target,indx+1);
    return res;
}

int climbStairs(int n , string psf){
    if(n == 0){
        cout<<psf<<endl;
        return 1;
    }
    if(n<0){
        return 0;
    }
    
    int ans = climbStairs(n-1 , psf + "1") + climbStairs(n-2 , psf + "2") + climbStairs(n-3 ,psf + "3");
    return ans;
}


int poww(int a, int b){
    if(b == 0){
        return 1;
    }
    if(a == 1){
        return 1;
    }

    int res = poww(a , b/2);
    res = res * res;
    if(b % 2 == 0){
        return res;
    }
    else{
        return res*a;
    }
}


//FInd the min in a vector
void findMIn(vector<int> &arr , int indx , int &min){
    if(indx == arr.size()){
        cout<<min<<endl;
        return;
    }
    if(arr[indx]<min){
        min = arr[indx];
    }
    findMIn(arr,indx+1,min);
    
}


// Infinite coins //
int sing_coin(vector<int> &arr , int idx , int target){
    if(target == 0){
        return 1;
    }
    if(target<0){
        return 0;
    }
    if(idx == arr.size()){
        return 0;
    }
    int ans = sing_coin(arr , idx , target - arr[idx]) + sing_coin(arr , idx+1 , target);
    return ans;
}




// Alternate Approach //
int helper(vector<int> & arr , int idx , int target){

    if(target==0){
        return 1;
    }
    
    int ans = 0;
    for(int i = idx ; i<arr.size() ; i++){
        if(arr[i] <= target){
            ans += helper(arr , i + 1 , target - arr[i]);
        }
    }
    return ans;
}

int helperInfi(vector<int> & arr , int idx , int target){

    if(target==0){
        return 1;
    }
    
    int ans = 0;
    for(int i = idx ; i<arr.size() ; i++){
        if(arr[i] <= target){
            ans += helperInfi(arr , i + 1 , target - arr[i]);
        }
    }
    return ans;
}


// Coin permu
int helperPermu(vector<int> & arr , int idx , int target){

    if(target==0){
        return 1;
    }
    
    int ans = 0;
    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i] <= target){
            ans += helperPermu(arr , i , target - arr[i]);
        }
    }
    return ans;
}





int main(){
    
    vector<int> arr = {1,2,3};
    int target = 4;
    cout<<helper(arr , 0 , target);
   

    return 0;
}