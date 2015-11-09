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

int n;
bool A[1100000];

int ans = 0;

int main()
{
	cin >> n;
	scan(A, 0, n);
	for (int i = 0; i < n; i ++)
		A[i+n] = A[i];	
	
	int start = -1;
	for (int i = 1; i < n; i ++)
	{
		if (A[i] == A[i-1] and A[i] == 1)
		{
			start = i-1;
			break;
		}
	}
	
	if (start == -1)
	{
		int sum = 0;
		for (int i = 1; i < n; i ++)
			sum += A[i];
			
		if (sum == n/2 and (n%2)==0)
		{
			cout << -1 << endl;
			return 0;
		}
		
		for (int i = 0; i < n; i ++)
			cout << "0 ";
		return 0;
	}
	bool digit = 1;
	for (int i = start, cnt = 0; cnt < n; cnt ++)
	{
		int j = i+1;
		while (cnt < n and A[j] == digit)
		{
			j ++;
			cnt ++;
		}
		i = j;
		//j = i;
		while (cnt+1 < n and A[j] == !digit and A[j+1] == digit)
		{
			j += 2;
			cnt += 2;
		}
		assert((i%2) == (j%2));
		if (A[j] == digit)
		{
			while (i < j)
			{
				A[i] = digit;
				i ++;
			}
			ans = max(ans, 2);
		} else
		{
			ans = max(ans, (i+j)/2 - i);
			for (int f = (i+j)/2; i < f; i ++, cnt ++)
			{
				A[i] = digit;
			}
			while (i < j)
			{
				A[i] = !digit;
				i ++;
				cnt ++;
			}
			digit = !digit;
		}
	}
	cout << ans << endl;
	for (int i = n; (i%n) < start; i ++)
		cout << A[i] << " ";
	for (int i = start; i < n; i ++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}


