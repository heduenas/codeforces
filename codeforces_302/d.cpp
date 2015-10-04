#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) ((1ll) << (_z))
using namespace std;

int n;
vector<int> G[400100];
long long DP[400100];
long long ans[400100];

const long long mod = 1000000007ll;

long long modpow(long long x, long long p)
{
	long long ret = 1;
	for (long long i = bit(0ll); i <= p; i <<= 1ll)
	{
		if (i & p)
		{
			ret *= x;
			ret %= mod;
		}
		x = (x * x) % mod;
	}
	return ret;
}

long long f(int nd, int pnt)
{
	DP[nd] = 1;
	for (int i = 0; i < G[nd].size(); i ++)
	{
		if (G[nd][i] == pnt)
			continue;
		DP[nd] *= f(G[nd][i], nd);
		DP[nd] %= mod;
	}
	DP[nd] ++;
	DP[nd] %= mod;
	return DP[nd];
}

long long g(int nd, int pnt, long long ak = 1)
{
	ans[nd] = ak;
	ans[nd] *= ((DP[nd] + mod - 1) % mod);
	ans[nd] %= mod;

	for (int i = 0; i < G[nd].size(); i ++)
	{
		if (G[nd][i] == pnt)
			continue;
		if (0)
			g(G[nd][i], nd, (((ans[nd] == DP[G[nd][i]])?1:((ans[nd] * modpow(DP[G[nd][i]], mod-2)) % mod)) + 1) % mod);
		else
		{
			long long par = ak;
			for (int k = 0; k < G[nd].size(); k ++)
			{
				if (G[nd][k] != pnt and G[nd][k] != G[nd][i])
				{
					par *= DP[G[nd][k]];
					par %= mod;
				}
			}
			par = (par + 1) % mod;
			g(G[nd][i], nd, par);
		}
	}
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i < n; i ++)
	{
		int a;
		scanf("%d", &a);
		G[a-1].push_back(i);
		G[i].push_back(a-1);
	}

	f(0, 0);
	g(0, 0);

	print(ans, 0, n);
	printf("\n");

	return 0;
}  	
