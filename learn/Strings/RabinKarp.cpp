#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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