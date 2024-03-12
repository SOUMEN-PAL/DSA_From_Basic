#include<bits/stdc++.h>
using namespace std;
#define d 256 

bool rabinKarp(string txt , string pat){
    int n = txt.length();
    int m = pat.length();
    
    int q = 97;
    int h = 1;
    for(int i = 0 ; i<m ; i++){
        h = (h*d)%q;
    }

    int t = 0 , p = 0;
    for(int i = 0 ; i<m ; i++){
        t = ((t * d) + int(txt[0]))%q;
        p = ((p*d) + int(pat[i]))%q;
    }

// Rolling hAsh //
    for(int i = 0 ; i<=n-m ; i++){
        if(p == t){
            bool flag = true;
	        for(int j = 0 ; j<m ; j++){
	            if(txt[i+j] != pat[j]){
	                flag = false;
	                break;
	            }
	        }
	        if(flag == true){
	            return true;
	        }
        }

        if(i<n-m){
            t = (((t - txt[i] * h) * d) + txt[i + m])%q;
            if(t<0){
                t = t+q;
            }
        }
    }
    return false;
}

int main(){
    
    return 0;
}