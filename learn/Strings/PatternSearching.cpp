#include<bits/stdc++.h>
using namespace std;


// Naive solution for pattern searching TC : O((n - m + 1) * m) n = length of text , m = length of pattern //
void naivePattern(string txt , string pat){
    int n = txt.length();
    int m = pat.length();
    for(int i = 0 ; i <= n - m ; i++){
        int j;
        for(j = 0 ; j < m ; j++){
            if(txt[i + j] != pat[j])
                break;
        }
        if(j == m)
            cout << i << " ";
    }
    cout << endl;
}

// Naive solution when pattern is distinct TC : O(n) overalll linear //
void naiveDistinctPattern(string txt , string patr){
    int n = txt.length();
    int m = patr.length();
    for(int i = 0 ; i<n ; ){
        int j;
        for(j = 0 ; j<m ; j++){
            if(txt[i + j] != patr[j])
                break;
        }
        if(j == m){
            cout << i << " ";
        }
        if(j == 0){
            i++;
        }
        else{
            i = i + j;
        }
    }
}

// TODO : Rabin Karp Algorithm //
int d = 256;
int q = 101;
void RBkarp(string txt , string pat){
    int n = txt.length();
    int m = pat.length();
    int h = 1;
    for(int i = 0 ; i < m - 1 ; i++){
        h = (h * d) % q;
    }
    int p = 0 , t = 0;
    for(int i = 0 ; i < m ; i++){
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for(int i = 0 ; i<= n-m ; i++){
        if(p == t){
            bool flag = true;
            for(int j = 0 ; j < m ; j++){
                if(txt[i + j] != pat[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){}
                cout << i << " ";
            }
        if(i < n - m){
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if(t < 0)
                t = t + q;
        }
    }
}


int main(){
    string s = "AABAACAADAABAABA";
    string p = "AABA";
    RBkarp(s , p);
    return 0;
}