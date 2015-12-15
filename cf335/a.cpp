#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <cassert>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctype.h>

#define deb(x) cout << #x << " = " << x << endl;
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;


struct BIT {
	long long data[100010];
	void init() {
//		memset(data, 128, sizeof data);
	}
	long long query(long long idx) {
		idx ++;
		long long ret = 0;
		while (idx) {
			ret = max(ret, data[idx]);
			idx -= idx & (-idx);
		}
		return ret;
	}
	long long update(long long idx, long long val) {
		idx ++;
		while (idx < 100010) {
			data[idx] = max(data[idx], val);
			idx += idx & (-idx);
		}
	}
} bit;

int n;
int A[100010];
int B[100010];

int solve()
{
	for (int i = 0; i < n; i ++)
	{
		bit.update(A[i], bit.query(A[i]) + 1);
	}
	return n - bit.query(n);
}

int solve2()
{
	int ret = 1;
	int cur = 1;
	for (int i = 2; i <= n; i ++)
	{
		if (B[i] > B[i-1])
			cur ++;
		else
			cur = 1;
		ret = max(ret, cur);
	}
	return n - ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
	{
		scanf("%d", &A[i]);
		B[A[i]] = i;
	}
//	print(B, 0, n+1);
	
	cout << solve2() << endl;
	
	return 0;
}
