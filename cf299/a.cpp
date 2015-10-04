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

long long A, B, n;
long long S(long long i)
{
	return A + (i-1) * B;
}

long long intS(long long b)
{
	assert(b >= 0);
	long long ret = b * (A - B);
	ret += b * ((b+1ll)/2ll);
	return ret;
}

bool f(long long mid, long long l, long long m, long long t)
{
	if (S(mid) > t)
		return 0;
	return (m * t) >= (intS(mid) - intS(l-1));
}

long long l, t, m;
long long solve()
{
	long long low = l-1, high = 10000000, mid;
	while (low < high)
	{
		mid = low + (high-low+1) / 2;
		if (false == f(mid, l, min(mid-l+1, m), t))
		{
			high = mid-1;
		}
		else
		{
			low = mid;
		}
	}
	if (low == l-1)
		return -1;
	return low;
}

int main()
{
	cin >> A >> B >> n;
	while(n--)
	{
		cin >> l >> t >> m;
		cout << solve() << endl;
	}

	return 0;
}


