// CPP program to modify a bit at position
// p in n to b.
#include <bits/stdc++.h>
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
