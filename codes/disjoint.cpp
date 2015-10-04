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
#define bit(_z) (1ll << _z)
using namespace std;

int n, p;
vector<int> G[2010];

int DP[1010][1010];

int f(int nd1, int nd2)
{
	if (nd1 == nd2)
		return nd1 == 1;
		
	if(nd1 < nd2)
		swap(nd1, nd2);
		
	if (DP[nd1][nd2] == -1)
	{
		DP[nd1][nd2] = 0;
		for (int i = 0; i < G[nd1].size(); i ++)
		{
			if (f(G[nd1][i], nd2) == 1)
				DP[nd1][nd2] = 1;
		}
	}
	return DP[nd1][nd2];
}

int main () 
{
	memset(DP, -1, sizeof DP);
	
	cin >> n >> p;
	for (int i = 0; i < p; i ++)
	{
		int a, b;
		cin >> a >> b;
		G[b].push_back(a);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
			if (f(i, j))
			{
				//cout << i << " " << j << " " << f(i, j) << endl;
				ans ++;
			}
	
	cout << ans - 1 << endl;
	
	return 0;
}  	
