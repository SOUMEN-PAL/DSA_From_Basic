#include <bits/stdc++.h>
using namespace std;

int ropecut( int n , int a , int b , int c){
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;
    }

    int res = max( ropecut(n-a , a , b , c) , max(ropecut(n-b , a , b , c) , ropecut(n-c , a , b , c)));

    if(res==-1){
        return -1; // edge case for the same value of a , b , c //
                    // Test case for which its written its n=9 ,a=2 , b = 2 , c = 2 //
    }
    return res+1;




}

int main(){
    int n , a , b , c;
    cout<<"Enter the length of the rope: ";
    cin>>n;
    cout<<"Enter the sub lengths"<<endl;;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;


    cout<<ropecut(n ,a, b ,c)<<endl;


    
    return 0;
}