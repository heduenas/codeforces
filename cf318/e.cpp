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

int n;
long long A[200100];
long long DP[2][200100];

int main()
{
	cin >> n;
	scan(A, 0, n);
	
	if (A[n-1] > 0)
		DP[0][n-1] = DP[1][n-1] = A[n-1];
	
	for (int i = n-2; i >= 0; i--)
	{
		long long opt = DP[0][i+1] + DP[1][i+1] + A[i];
		if (DP[0][i+1] > opt)
		{
			DP[0][i] = DP[0][i+1];
			DP[1][i] = DP[1][i+1];
		}
		else
		{
			DP[0][i] = opt;
			DP[1][i] = DP[1][i+1] + A[i];
			cout << A[i] << endl;
		}
	}
	
	cout << DP[0][0] << endl;
	
	return 0;
}


