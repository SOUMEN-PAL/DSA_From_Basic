#include <bits/stdc++.h>
using namespace std;

int count(int n){
    int count = 0;
    while(n!=0){
        count++;
        n=n/10;
    }
    return count;
}

bool ams(int n){
    int sum = 0;
    int a= n;
    int p = count(n);
    while(a!=0){
        int x = a%10;
        sum = sum + pow(x,p);
        a = a/10;
    }
    if(sum==n){
        return true;
    }
    else{
        return false;
    }

}


int main(){
    int a;
    cin>>a;
    cout<<ams(a)<<endl;;
    return 0;
}