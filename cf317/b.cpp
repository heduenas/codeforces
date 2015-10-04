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

long long n, k;
long long A[600100];
long long* DP[301000];
long long a;

long long f(long long alpha, long long beta, long long idx)
{
	
	if (alpha == 0 and beta == 0)
		return 0;
	if (DP[alpha][beta] == -1)
	{
		DP[alpha][beta] = bit(63)-1;
		if (alpha)
			DP[alpha][beta] = A[idx + a-1] - A[idx] + f(alpha-1, beta, idx+a);
		if (beta and DP[alpha][beta] > A[idx + a] - A[idx] + f(alpha, beta-1, idx+a+1))
		{
			DP[alpha][beta] = A[idx + a] - A[idx] + f(alpha, beta-1, idx+a+1);
		}
	}
	return DP[alpha][beta];
}

int main()
{
	cin >> n >> k;
	scan(A, 0, n);
	sort(A, A + n);
	
	long long alpha, beta = 0;
	a = n / k;
	/*for (alpha = 2*k; alpha > 0; alpha --)
	{
		if (((n - alpha * a)%(a+1)) == 0)
		{
			//deb((n - alpha * a) / (a+1))
			beta = (n - alpha * a) / (a+1);
			if (beta > 0)
				break ;
		}
	}*/
	beta = n % k;
	alpha = k - beta;
	//if (n == 10002)
	{
	//deb(a) deb(alpha); deb(beta);
	}
	
	for (long long i = 0; i <= alpha+1; i ++)
	{
		DP[i] = new long long[beta+2];
		memset(DP[i], -1, sizeof(long long) * (beta+2));
	}
	
	cout << f(alpha, beta, 0) << endl;
	
	return 0;
}


