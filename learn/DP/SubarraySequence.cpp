#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

// ---------- Helper: Modular Multiplication ----------
ll modMul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

// ---------- First Implementation: O(n log n) using recurrence (T vector) ----------
ll calcEfficient(vector<int>& arr) {
    int n = arr.size();
    // Sort the array (non-decreasing order)
    sort(arr.begin(), arr.end());
    
    // Contribution from single-element subsequences: arr[i]^3
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll cube = modMul(modMul(arr[i], arr[i]), arr[i]);
        ans = (ans + cube) % mod;
    }
    
    // Compute T[j] for j = 1 to n-1:
    // T[j] = sum_{i=0}^{j-1} arr[i] * 2^(j-i-1)
    // with recurrence: T[0] = 0; T[j+1] = 2*T[j] + arr[j]
    vector<ll> T(n, 0);
    if(n > 0)
        T[0] = 0;
    if(n > 1)
        T[1] = arr[0];
    
    for (int j = 1; j < n - 1; j++){
        T[j+1] = (2 * T[j] + arr[j]) % mod;
    }
    
    // For each j from 1 to n-1, add contribution: arr[j]^2 * T[j]
    for (int j = 1; j < n; j++){
        ll term = modMul(modMul(arr[j], arr[j]), T[j]);
        ans = (ans + term) % mod;
    }
    
    return ans;
}

// ---------- Second Implementation: Recursive brute-force approach ----------

ll sumGlobal = 0;
void helper(const vector<int> &arr, int n, int i, int max_v, int min_v) {
    if (i == n) {
        if (max_v == INT_MIN || min_v == INT_MAX) return;
        sumGlobal = (sumGlobal + (((ll)max_v * max_v % mod) * min_v) % mod) % mod;
        return;
    }
    // "Take" the current element
    helper(arr, n, i + 1, max(max_v, arr[i]), min(min_v, arr[i]));
    // "Skip" the current element
    helper(arr, n, i + 1, max_v, min_v);
}

ll calcRecursive(vector<int>& arr) {
    int n = arr.size();
    sumGlobal = 0;
    // Use INT_MIN and INT_MAX as initial values for max and min respectively.
    helper(arr, n, 0, INT_MIN, INT_MAX);
    return sumGlobal;
}

// ---------- Third Implementation: Combinatorial Counting using Prefix Sums and Powers of 2 ----------

int maxSquareMinSubsequences(vector<int>& arr) {
    int n = arr.size();
    // Sort the array so that for any pair (i, j) with i < j, arr[i] is min and arr[j] is max.
    sort(arr.begin(), arr.end());
    
    // Precompute powers of 2 modulo mod.
    vector<int> pow2(n, 1);
    for (int i = 1; i < n; i++) {
        pow2[i] = ( (long long) pow2[i - 1] * 2 ) % mod;
    }
    
    // Compute prefix sums of the sorted array.
    vector<int> prefix_sum(n, 0);
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = (prefix_sum[i - 1] + arr[i]) % mod;
    }
    
    int result = 0;
    // For each possible maximum element arr[i] (with i >= 1), the number of subsequences where
    // an earlier element is the minimum is given by:
    //   arr[i]^2 * (prefix_sum[i-1] * pow2[i-1])
    // (Because for each j (i being max), each i < j gives 2^(j-i-1) choices.)
    for (int i = 1; i < n; i++) {
        int max_square = ( (long long) arr[i] * arr[i] ) % mod;
        int min_contribution = ( (long long) prefix_sum[i - 1] * pow2[i - 1] ) % mod;
        result = (result + ( (long long) max_square * min_contribution ) % mod) % mod;
    }
    
    // Add the single-element subsequences: each contributes arr[i]^3.
    for (int i = 0; i < n; i++){
        int cube = ( (long long) arr[i] * arr[i] % mod * arr[i] ) % mod;
        result = (result + cube) % mod;
    }
    
    return result;
}

// ---------- Main Function to Compare Implementations ----------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Read the array; we keep copies because some functions sort the array.
    vector<int> arr1(n), arr2(n), arr3(n);
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    arr2 = arr1;
    arr3 = arr1;
    
    ll efficientAns = calcEfficient(arr1);
    ll recursiveAns = calcRecursive(arr2);
    int countingAns = maxSquareMinSubsequences(arr3);
    
    cout << "Efficient (T vector) solution: " << efficientAns << "\n";
    cout << "Recursive brute-force solution: " << recursiveAns << "\n";
    cout << "Counting (prefix sum & pow2) solution: " << countingAns << "\n";
    
    return 0;
}
