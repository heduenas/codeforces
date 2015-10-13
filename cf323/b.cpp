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

int n, t, A[210];
int X[2000100];
int lis[2000100];
int aux[310];

int ans = 0;

int rep[310];
int repmax;

int main()
{
	cin >> n >> t;
	scan(A, 0, n);
	
	for (int i = 0; i < n; i ++)
		rep[A[i]] ++;
	for (int i = 1; i <= 300; i ++)
		repmax = max(repmax, rep[i]);
	
	for (int i = 0; i < n*min(n * n, t); i ++)
	{
		X[i] = A[i%n];
	}
	
	for (int i = 0; i < n*min(n * n, t); i ++)
	{
		for (int k = 1; k <= X[i]; k ++)
		{
			lis[i] = max(lis[i], aux[k]+1);
		}
		aux[X[i]] = max(aux[X[i]], lis[i]);
		
		ans = max(ans, lis[i]);
	}
	
	ans += repmax * (t - min(n * n, t));
	
	//deb(repmax);
	
	cout << ans << endl;

	return 0;
}


