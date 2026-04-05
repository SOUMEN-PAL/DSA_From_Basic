#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cout << s[i - 1] << s[i] << endl;
                found = true;
                break;
            }
        }
        if (found == false) {
            for (int i = 2; i < n; i++) {

                unordered_set<char> hs;
                hs.insert(s[i]);
                hs.insert(s[i - 1]);
                hs.insert(s[i - 2]);
                if (hs.size() == 3) {
                    cout << s[i - 2] << s[i - 1] << s[i] << endl;
                    found = true;
                    break;
                }

            }
        }


        if (found == false) {
            cout << "-1" << endl;
        }

    }




    return 0;
}