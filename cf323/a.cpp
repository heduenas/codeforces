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

priority_queue<int> Q;

long long n, A[300100], ans[1100], ansl;

int main()
{
	cin >> n;
	scan(A, 0, n*n);
	
	sort(A, A+(n*n));
	reverse(A, A+(n*n));
	
	for (int i = 0; i < n*n;)
	{
		int cnt = 0, cnt2 = 0;
		for (; A[i+cnt] == A[i]; cnt ++);
		while (!Q.empty() and Q.top() > A[i])
			Q.pop();
		while (!Q.empty() and Q.top() == A[i])
		{
			cnt2 ++;
			Q.pop();
		}
		
		int mult = 0;
		for (int j = 0; j < ansl; j ++)
			if ((ans[j] % A[i]) == 0)
				mult ++;
				
		int rep;
		for (rep = 0; rep < n-ansl; rep ++)
		{
			if (2*mult*rep + rep*rep == cnt-cnt2)
				break;
		}
		
		for (int j = 0; j < ansl; j ++)
		{
			for (int k = 0; k < rep; k ++)
			{
				Q.push(__gcd(ans[j], A[i]));
				Q.push(__gcd(ans[j], A[i]));
			}
		}
		
		while (rep --)
		{
			ans[ansl++] = A[i];
		}
		i += cnt;
		
		/*deb(cnt);
		deb(A[i]);
		deb(i);*/
	}
	
	assert(n == ansl);
	
	print(ans, 0, n);
	cout << endl;

	return 0;
}


