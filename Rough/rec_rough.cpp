#include <bits/stdc++.h>
using namespace std;
/*
long long sumif(long long n , long long k = 0){

    if((k%10)!=k){  <------ i was checkig here if the sum is a two digit no or not 
        return sumif(k);
    }



    if(n==0){
        return k; <---- here i was thinking of returning the sum and i am returning k because its a tail recursive approach 
    }



    return sumif(n/10 , k+(n%10));

} this approach is the wrong approach i do not know where is the problem in logic but ya i will see it later 
*/

int digitalroot(int n){
    if(n==0){
        return 0;
    }

    int x = digitalroot(n/10)+n%10;
    return digitalroot(x/10)+x%10;
}

int main(){
    cout<<digitalroot(1056);


    return 0;
}