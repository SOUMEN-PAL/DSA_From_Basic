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
vector<int> res;
vector<int> allIndx(vector<int> &arr , int target , int indx){
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

int climbStairs(int n){
    if(n == 0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans = climbStairs(n-1) + climbStairs(n-2) + climbStairs(n-3);
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




int main(){
    
    // int res = climbStairs(3);
    // cout<<res<<endl;
    cout<<poww(2 , 3)<<endl;

    return 0;
}