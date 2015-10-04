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

int n, k;
long long A[500100], x, X=1;
long long C[500100][2];

int main()
{
	cin >> n >> k >> x;
	scan(A, 0, n);
	
	//sort(A, A+n);
	
	for (int i = 0; i < k; i ++)
	{
		X *= x;
	}
	
	//cerr << X << endl;
	
	for (int i = n-1; i > 0; i --)
	{
		C[i][1] = C[i+1][1] | A[i];
	}
	
	C[0][0] = A[0];
	for (int i = 1; i < n; i ++)
	{
		C[i][0] = C[i-1][0] | A[i];
		//cerr << C[i][0] << " " << C[i][1] << endl;
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i ++)
	{
		ans = max(ans, (i>0?C[i-1][0]:0ll) | (X * A[i]) | C[i+1][1] );
	}
	
	cout << ans << endl;
	
	return 0;
}


