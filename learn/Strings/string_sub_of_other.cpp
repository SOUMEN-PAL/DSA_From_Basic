#include<bits/stdc++.h>
using namespace std;


// Naive solution O(2^n) time complexity and AS: O(2^n) because of recurssion call stack //
void solve(string str,string output,int index,unordered_set<string> & ans){

    if(index>=str.length()){

        ans.insert(output);

        return ;

    }

    solve(str,output,index+1,ans);



    solve(str,output+str[index],index+1,ans);

}


bool isSubSequence(string A, string B)
{
    unordered_set<string> hs;
    solve(B , "" , 0 , hs);
    if(hs.find(A) != hs.end()){
        return true;
    }
    return false;
}
 // Itreative O(n) solution //
bool in_subsequence(string A, string B)
{
    int j = 0;
    for(int i = 0 ; i<B.length() ; i++){
        if(B[i] == A[j]){
            j++;
        }
    }
    return (j==A.length());
}

//Recurssive SOlution //
bool is_subSequence(string A , string B , int n , int m){
    if(n==0){
        return true;
    }
    if(m==0){
        return false;
    }
    if(A[n-1] == B[m-1]){
        return is_subSequence(A , B , n-1 , m-1);
    }
    else{
        return is_subSequence(A , B , n-1 , m);
    }
}

int main(){
    string str1 = "AB";
    string str2 = "ACDB";
    cout<<isSubSequence(str1 , str2)<<endl;
    cout<<in_subsequence(str1 , str2)<<endl;
    cout<<is_subSequence(str1 , str2 , str1.length() , str2.length())<<endl;
    return 0;
}