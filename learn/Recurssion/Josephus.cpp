#include <bits/stdc++.h>
using namespace std;

// int jos(int n , int k ){
//     if(n==1){
//         return 0;
//     }
//     else{
//         return (jos(n-1 , k)+k)%n;
//     }

// }

int jos(int n, int k) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + k) % i;
    }
    return result;
}


int main(){
    int N , k;
    cout<<"Enter vlaue of N: ";
    cin>>N;

    cout<<"Sequence to kill: ";
    cin>>k;

    int res = jos(N , k);
    cout<<"The person alive is: "<<res<<endl;


    return 0;
}