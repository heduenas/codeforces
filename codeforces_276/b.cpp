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

const int lim =400005;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n;
int A[lim];
int ans = 0;

int main()
{
	cin >> n;
	scan(A, 0, n);
	sort(A, A + n);
	
	int rep = 0;
	for (int i = 1; i < n; i ++)
	{
		if (A[i] == A[i-1])
			rep ++;
		A[i-rep] = A[i];
	}
	n -= rep;
	
	for (int i = n-1; i >= 0 and A[i] > ans; i --)
	{
		for (int j = i; j < n; j ++)
		{
				ans = max(ans, A[j] % A[i]); 
		}
	}
	
	cout << ans << endl;

    return 0;
}


