// CPP program to modify a bit at position
// p in n to b.
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

// Returns modified n.
int modifyBit(int n, int p, int b)
{
	int mask = 1 << p;
	return ((n & ~mask) | (b << p));

}

// Driver code
int main()
{
	cout << modifyBit(5, 1, 1) << endl;

	return 0;
}
