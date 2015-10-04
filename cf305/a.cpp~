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
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

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


long long m;
long long h1, a1, Y1, x1, h2, a2, y2, x2;

bool mem[1000010];
long long walk(long long h, long long x, long long y, long long a)
{
	long long it = 0;
	memset(mem, 0, sizeof mem);
	while ((!mem[h]) and (h != a))
	{
		mem[h] = 1;
		it ++;
		h = h * x + y;
		h %= m;
	}
	
	if(h == a)
		return it;
	else
		return -1;
}

long long solve(long long c1, long long t, long long c2)
{
	while(t < 0);
	for (long long i = 0; i <= c2; i ++)
	{
		if (((i * c1) % c2) == t)
			return i;
	}
	return -1;
}

int main()
{
	cin >> m;
	cin >> h1 >> a1;
	cin >> x1 >> Y1;
	cin >> h2 >> a2;
	cin >> x2 >> y2;
		
	long long t1 = walk(h1, x1, Y1, a1);
	long long c1 = (walk((a1 * x1 + Y1)%m, x1, Y1, a1) + 1);
	long long t2 = walk(h2, x2, y2, a2);
	long long c2 = (walk((a2 * x2 + y2)%m, x2, y2, a2) + 1);
	
	if (t1 == -1 or t2 == -1)
	{
		cout << -1 << endl;
	}
	else if (c1 == -1 or c2 == -1)
	{
		if (t1 == t2)
			cout << t1 << endl;
		else if (c1 + c2 != -2)
		{
			if (c1 == -1)
				swap(c1, c2);
			if (t2 > t1 and ((c1 % (t2-t1)) == 0))
				cout << t2 << endl;
			else
				cout << -1 << endl;
		}
		else
			cout << -1 << endl;
	}
	else
	{
		if (c1 > c2)
		{
			swap(c1, c2);
			swap(t1, t2);
		}
		long long ans = solve(c1, (t2-t1+1000000ll*c2)%c2, c2);
		if (ans != -1)
			ans = t1 + c1 * ans;
		cout << ans << endl;
	}
		
	return 0;
}


