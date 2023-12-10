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
            cout<<i+1<<endl;
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

void eff_Lexographic_rank(string s){
    int n = s.length();
    int mul = factorial(n);
    int rank = 1; // rank of the string //
    int count[256] = {0};
    for(int i = 0 ; i<n ; i++){
        count[s[i]]++; // storing the count of each character //
    }
    for(int i = 1 ; i<256 ; i++){
        count[i] += count[i-1]; // storing the count of characters less than the current character //
    }

    for(int i = 0 ; i<=n-2 ; i++){
        mul = mul/(n-i); // updating the factorial // // all the permutations of the remaining characters //
        rank = rank + count[s[i] - 1] * mul; // updating the rank //
        for(int j = s[i] ; j<256 ; j++){
            count[j]--; // removing the current character from the count //
        }
    }
    cout<<rank<<endl;
    
}


int main(){
    Lexographic_rank("STRING");
    eff_Lexographic_rank("STRING");
    
    return 0;
}
