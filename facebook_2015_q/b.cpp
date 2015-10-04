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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int t, n;
int a, b, c;
int A[100], B[100], C[100];

bool solve()
{
	for (int subset = 0; subset < bit(n); subset ++)
	{
		int totA = 0, totB = 0, totC = 0;
		for (int i = 0; i < n; i ++)
			if (subset & bit(i))
			{
				totA += A[i];
				totB += B[i];
				totC += C[i];
			}
		if (totA == a and totB == b and totC == c)
			return true;
	}
	return false;
}

int main()
{
	cin >> t;
	int caze = 0;
	while (t--)
	{
		caze ++;
		cin >> a >> b >> c;
		cin >> n;
		for (int i = 0; i < n; i ++)
		{
			cin >> A[i] >> B[i] >> C[i];
		}

		cout << "Case #" << caze << ": " << (solve()?"yes":"no") << endl;
	}
	return 0;
}
