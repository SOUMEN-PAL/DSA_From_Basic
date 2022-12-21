#include <iostream>
#include <math.h>
using namespace std;

void primefactor(int n){
    if(n<=1){return;}
    for(int i=2 ; i*i<=n;i++){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i; // removing the factor for which i has been printed //
// in naive solution we were modifying the x value aka values and multiples of i//
// but now we are removing the factors form the given no n so if we remove factors of prime and printing the values we got the prime factors//        
        }
    }
    if(n>1){
        cout<<n<<" "; // code for the edge casses //
    }
// the starting prime 2 and 3 divides all the nos to the end 
    cout<<endl;
}

/*factors always appears in pairs and always the smaller factor is a prime mostly so 
we ran a while loop in the for loop and it prints i if the n%i==0 then
we divide the number n with i so that we remove the multiple of that no 
kinda opposite of the naive solution */

int main(){
    
    primefactor(96);
// what i was again thinking was checking the prime then printing it but it was again the naive solution //


    return 0;
}