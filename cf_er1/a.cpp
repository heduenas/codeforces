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

long long t, n;

long long largestbit(long long num)
{
	while (num - (num & (-num)))
		num -= num & (-num);
	return num;
}

int main()
{
	cin >> t;
	while (t --)
	{
		cin >> n;
		
		cout << (n * (n+1)) / 2 - 2 * (2 * largestbit(n)) + 2 << endl;
	}

	return 0;
}


