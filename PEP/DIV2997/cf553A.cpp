#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long modInverse(long long a, long long m) {
    long long res = 1, base = a;
    long long exp = m - 2; // Fermat's Little Theorem
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res;
}

int nCr(int n, int r) {
    if (r > n) return 0; 
    if (r == 0 || r == n) return 1; 

    long long sum = 1;
    for (int i = 1; i <= r; i++) {
        long long a = (n - r + i) % mod;
        long long b = modInverse(i, mod); // Modular inverse
        sum = (sum * ((a * b) % mod)) % mod;
    }
    return static_cast<int>(sum);
}

int main() {
    int n;
    cin >> n;
    long long res = 0;
    long long totalBalls = 0;
    while (n--) {
        int a;
        cin >> a;
        
        if (res == 0) {
            res = 1;
        } else {
            int r = a - 1;
            int value = nCr(totalBalls + r, r);
            res = (res * value) % mod;
        }

        totalBalls += a;
    }

    cout << res << endl;

    return 0;
}


// int GCDExtended(long long a , long long b , long long &x , long long &y){
//     if(a == 0){
//         x = 0;
//         y = 1;
//         return b;
//     }

//     long long X , Y;
//     long long gcd = GCDExtended(b%a , a , X , Y);


//     x = Y-(b/a) * X;
//     y = X;
    
//     return gcd;

// }
