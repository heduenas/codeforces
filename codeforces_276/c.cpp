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
long long A[1000100];
long long DP[2][1000100];

int main()
{
	cin >> n;
	scan(A, 0, n);

		for (int pos = n-1; pos >= 1; pos --)
		{
			DP[0][pos] = max(DP[1][pos+1], DP[0][pos+1]);
			if (A[pos] >= A[pos-1])
			{
				DP[0][pos] = max(DP[0][pos], A[pos] - A[pos-1] + DP[0][pos+1]);
			}
			
			DP[1][pos] = max(DP[1][pos+1], DP[0][pos+1]);
			if (A[pos] <= A[pos-1])
			{
				DP[1][pos] = max(DP[1][pos], A[pos-1] - A[pos] + DP[1][pos+1]);
			}
		}
		
	cout << max(DP[0][1], DP[1][1]) << endl;
	
    return 0;
}


