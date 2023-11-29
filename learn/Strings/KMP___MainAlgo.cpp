#include<bits/stdc++.h>
using namespace std;

// Creation of the LPS array in O(n) //
void fillLPS(string str , int n , int LPS[]){
    int i = 1;
    int len = 0;
    LPS[0] = 0;
    while(i<n){
        if(str[i] == str[len]){
            len++;
            LPS[i] = len;
            i++;
        }
        else{
            if(len == 0){
                LPS[i] = 0;
                i++;
            }
            else{
                len = LPS[len - 1];
            }
        }
    }
}

void KMP(string str , string pat){
    int n = str.length();
    int m = pat.length();
    int LPS[m];
    fillLPS(pat , m , LPS);
    int i = 0;
    int j = 0;
    while(i<n){
        if(str[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            cout<<"Pattern detected at index: "<<i-j<<endl;
            j = LPS[j-1];
        }
        else if(i<n && str[i] != pat[j]){
            if(j == 0){
                i++;
            }
            else{
                j = LPS[j-1];
            }
        }
    }
}

int main(){
    string str = "ababcababaad";
    string pat = "ab";
    KMP(str , pat);

    

    
    return 0;
}