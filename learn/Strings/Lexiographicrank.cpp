#include<bits/stdc++.h>
using namespace std;


// Naive solution //
// Factorial n permutations //
void permutations(string s ,  vector<string> &v ,int l = 0){
    if(l==s.length()-1){
        v.push_back(s);
        return;
    }
    for(int i = l ; i<=s.length()-1 ; i++){
        swap(s[l] , s[i]);
        permutations(s , v , l+1);
        swap(s[l] , s[i]);
    }
}

// O(n*n!) //
void Lexographic_rank(string s){
    vector<string> v;
    permutations(s , v);
    sort(v.begin() , v.end());
    for(int i = 0 ; i<v.size() ; i++){
        if(v[i]==s){
            cout<<i+1;
            break;
        }
    }
}


// Efficient Solution //
// O(n) //

int factorial(int n){
    if(n==0 || n==1) return 1;
    int fact = 1;
    for(int i = 2 ; i<=n ; i++){
        fact*=i;
    }
    return fact;
}

void Lexographic_rank(string s){
    
    int count[256] = {0};
    int rank = 1;
}


int main(){
    Lexographic_rank("STRING");
    
    return 0;
}
