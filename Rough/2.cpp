#include<bits/stdc++.h>
using namespace std;


int convertRoman(string& s){
    map<char, int> m; 
    m.insert({ 'I', 1 }); 
    m.insert({ 'V', 5 }); 
    m.insert({ 'X', 10 }); 
    m.insert({ 'L', 50 }); 
    m.insert({ 'C', 100 }); 
    m.insert({ 'D', 500 }); 
    m.insert({ 'M', 1000 }); 

    int res = 0;
    for(int i = 0 ; i<s.length() ; i++){
        if(m[s[i]] < m[s[i+1]]){
            res += m[s[i+1]] - m[s[i]];
            i++;
            continue;
        }
        res += m[s[i]];
    }
    return res;
}

int main(){
    string str = "MCMIV"; 
    cout << "Integer form of Roman Numeral is " <<  
             convertRoman(str) << endl; 
    
    return 0;
}