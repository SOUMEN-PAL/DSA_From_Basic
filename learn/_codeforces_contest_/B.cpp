#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

/*
B. Having Been a Treasurer in the Past, I Help Goblins Deceive
time limit per test
2 seconds
memory limit per test
256 megabytes

After completing the first quest, Akito left the starting cave. After a while, he stumbled upon a goblin village.

Since Akito had nowhere to live, he wanted to find out the price of housing. It is well known that goblins write numbers as a string of characters '-' and '_', and the value represented by the string s
is the number of distinct subsequences∗ of the string s

that are equal to the string "-_-" (this is very similar to goblin faces).

For example, the string s=
"-_--_-" represents the number 6, as it has 6

subsequences "-_-":

    s1+s2+s3

s1+s2+s4
s1+s2+s6
s1+s5+s6
s3+s5+s6
s4+s5+s6

Initially, the goblins wrote a random string-number s
in response to Akito's question, but then they realized that they wanted to take as much gold as possible from the traveler. To do this, they ask you to rearrange the characters in the string s so that the value of the number represented by the string s

is maximized.

∗
A subsequence of a string a is a string b that can be obtained by deleting several (possibly 0) characters from a

. Subsequences are considered different if they are obtained by deleting different sets of indices.
Input

The first line contains the number t
(1≤t≤104

) — the number of test cases.

In the first line of each test case, there is one number n
(1≤n≤2⋅105

) — the length of the string written by the goblins.

In the second line of each test case, there is a string s
of length n

, consisting only of characters '-' and '_' — the string written by the goblins.

It is guaranteed that the sum of n
across all test cases does not exceed 2⋅105

.
Output

For each test case, you need to output one number — the maximum number of subsequences equal to the string "-_-", if the characters in the string s

are optimally rearranged.
Example
Input
Copy

8
3
--_
5
__-__
9
--__-_---
4
_--_
10
_-_-_-_-_-
7
_------
1
-
2
_-

Output
Copy

1
0
27
2
30
9
0
0

Note

In the first test case, it is beneficial to rearrange the characters to form the string "-_-". This is the only string of three characters that has at least one subsequence "-_-".

In the second test case, there is only one character "-", and at least two are needed for the subsequence "-_-". This means that for any rearrangement of characters, the answer will be 0

.

In the seventh and eighth test cases, the length of the string n<3
, which means that subsequences of length 3 do not exist.*/

int nCr(int n, int r) {
    if (r > n) return 0; // nCr is undefined for r > n
    if (r == 0 || r == n) return 1; // Base cases: nC0 = nCn = 1
    
    long long sum = 1;
    for (int i = 1; i <= r; i++) {
        sum = sum * (n - r + i) / i;
    }
    return static_cast<int>(sum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        string s;
        cin>>n>>s;
        ll cntU = 0 , cntD = 0;
        for(int i = 0 ; i<n ; i++){
            if(s[i] == '_'){
                cntU++;
            }
            else{
                cntD++;
            }
        }
        ll ans = 0;
        
        if(cntD < 2 || cntU == 0)
            ans = 0;
        else
            ans = cntU * ( (cntD/2) ) * ( (cntD - cntD/2) );
        cout<<ans<<endl;
    }
    
    return 0;
}