#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long double dd;
#define pb push_back
#define all(x) x.begin(),x.end()
#define gcd(a,b) __gcd(a,b)
#define popcount(x) __builtin_popcountll(x)

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
}

void solve(int tt)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> div;
    for (int i=1; i*i<=n; i++)
    {
        if (n%i==0)
        {
            div.pb(i);
            if (n/i != i)
                div.pb(n/i);
        }
    }
    sort(all(div));
    for (int i=0; i<div.size(); i++)
    {
        int len=div[i];
        string check1=s.substr(0,len);
        string check2=s.substr(n-len,len);
        int cnt1=0,cnt2=0;
        for (int j=0; j<n; j+=len)
        {
            for (int k=j; k<j+len; k++)
            {
                if (s[k]!=check1[k%len])
                    cnt1++;
                if (s[k]!=check2[k%len])
                    cnt2++;
            }
        }
        if (cnt1<2 || cnt2<2)
        {
            cout<<len<<endl;
            return;
        }
    }
}    

signed main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt=1;
    cin>>tt;
    while (tt--)
        solve(tt);
    return(0);
}