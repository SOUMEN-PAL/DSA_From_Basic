#include <iostream>
#include <vector>

using namespace std;

vector<int> constructPermutation(int N, int K) {
    vector<int> permutation(N);
    for (int i = 0; i < N; i++) {
        permutation[i] = i + 1;
    }

    // Swap adjacent elements to make the sum odd
    for (int i = 0; i < N - 1 && K > 0; i += 2, K--) {
        swap(permutation[i], permutation[i + 1]);
    }

    return permutation;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> permutation = constructPermutation(N, K);

        for (int i = 0; i < N; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
