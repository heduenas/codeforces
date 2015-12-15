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

#define par pair<pair<int, int>, int>
#define p1 first.first
#define p2 first.second
#define p3 second

#define eps = 1e-6

using namespace std;

int n, m;
par E[100100];
int V[100100][2];

bool solve()
{
	for (int i = 0; i < n-1; i ++)
	{
		V[E[i].p3][0] = i+1;
		V[E[i].p3][1] = i+2;
	}
	int j = n-1;
	for (int i = 2; i < n; i ++)
	{
		for (int k = 0; k < i-1 and j < m; k++, j++)
		{
			if (E[j].p2 < E[i-1].p2)
				return false;
			V[E[j].p3][0] = k+1;
			V[E[j].p3][1] = i+1;
		}
	}
	
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++)
	{
		scanf("%d%d", &E[i].p2, &E[i].p1);
		E[i].p1 = !E[i].p1;
		E[i].p3 = i;
	}
	
	sort(E, E+m);
	
	if (!solve())
		cout << -1 << endl;
	else
		for (int i = 0; i < m ; i ++)
		{
			printf("%d %d\n", V[i][0], V[i][1]);
		}
	
	return 0;
}
