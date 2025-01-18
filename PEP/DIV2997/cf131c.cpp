#include <bits/stdc++.h>
using namespace std;

long long nCr(long long n, long long r) {
    if (r > n) return 0; // nCr is undefined for r > n
    if (r == 0 || r == n) return 1; // Base cases: nC0 = nCn = 1

    long long result = 1;
    for (long long i = 1; i <= r; i++) {
        result = result * (n - r + i) / i;
    }
    return result;
}

int main() {
    int nBoys, nGirls, need;
    cin >> nBoys >> nGirls >> need;

    long long totalWays = 0;

    // Iterate over possible number of boys (b) in the group
    for (int b = 4; b <= min(nBoys, need - 1); b++) {
        int g = need - b; // Remaining actors must be girls
        if (g >= 1 && g <= nGirls) { // Valid number of girls
            long long waysBoys = nCr(nBoys, b);
            long long waysGirls = nCr(nGirls, g);
            totalWays += waysBoys * waysGirls;
        }
    }

    cout << totalWays << endl;
    return 0;
}




/*
#include<bits/stdc++.h>
using namespace std;

long long nCr(long long n, long long r) {
    if (r > n) return 0; // nCr is undefined for r > n
    if (r == 0 || r == n) return 1; // Base cases: nC0 = nCn = 1

    long long sum = 1;
    for (long long i = 1; i <= r; i++) {
        sum = sum * (n - r + i) / i;
    }
    return sum;
}



int main(){
    int nBoys , nGirls , need;
    cin>>nBoys>>nGirls>>need;

    int veleBache = nBoys + nGirls - 5;

    long long CB = nCr(nBoys , 4);
    long long CG = nCr(nGirls , 1);

    int remaning_need = need - 5;
    long long veleMe = nCr(veleBache , remaning_need);
    long long ans = CB * CG * veleMe;
    cout<<ans<<endl;

    return 0;
}
*/