#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    if(n == 2){ return true;}
    
    if(n%2 == 0){
        return false;
    }
    for(int i = 3 ; i*i<=n ; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

string winner(int n){
        // sidha kam //
        if(n%2 == 0){
            return "Bob";
        }
        if(isPrime(n)){
            return "Alice";
        }
        
        // now agar alice ko jitna ha use koi odd number mila toh use prime uthana hoga right? then woh bas odd number utaigi right? jitne ke liye 
        for(int p = 3 ; p < n ; p++){
            if(isPrime(p)){
                return "ALice";
            }
        }
        return "Bob";
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        cout<<winner(n)<<endl;
        
        
	}
	return 0;
}
