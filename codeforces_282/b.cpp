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

int n;
int m;
char s[100100], t[100100];

int prev[100100][26];
int u[100100];
int end[100100];

const int mod = 1000000007;
int DP[100100][2];

int f(int idx, int st)
{
	if (idx == n)
		return 1;
		
	if (DP[idx][st] == -1)
	{
		DP[idx][st] = 0;
		if (st == 0)
		{
			DP[idx][st] += f(idx+1, 0);
			DP[idx][st] %= mod;
			if (end[idx] != -1)
			{
				DP[idx][st] += f(end[idx]+1, 1);
				DP[idx][st] %= mod;
			}
		} else
		{
			DP[idx][st] += f(idx+1, 1);
			DP[idx][st] %= mod;
			DP[idx][st] += f(idx+1, 0);
			DP[idx][st] %= mod;
			if (end[idx] != -1)
			{
				DP[idx][st] += f(end[idx]+1, 1);
				DP[idx][st] %= mod;
			}
		}
	}
	return DP[idx][st];
}

void fill_end()
{
	queue<int> Q[2];
	for (int i = n-1; i >= 0; i --)
	{
		if (s[i] == t[m-1])
		{
			Q[(m-1)%2].push(i);
			u[i] = i;
		}
	}
	
	for (int idx_t = m-1; idx_t > 0; idx_t --)
	{
		while (!Q[idx_t%2].empty())
		{
			int idx = Q[idx_t%2].front();
			Q[idx_t%2].pop();
			
			if (prev[ idx ][ t[idx_t-1]-'a' ] == -1)
				continue ;
			
			u[prev[ idx ][ t[idx_t-1]-'a' ]] = u[idx];
			Q[(idx_t+1)%2].push(prev[ idx ][ t[idx_t-1]-'a' ]);
		}
	}
	
	while (Q[0].empty() == false)
	{
		end[Q[0].front()] = u[Q[0].front()];
		Q[0].pop();
	}
	
	for (int i = n-2; i >= 0; i --)
	{
		if (end[i] == -1)
			end[i] = end[i+1];
		else if (end[i+1] != -1)
			end[i] = min(end[i], end[i+1]);
	}
}

int main () {
	memset(u, -1, sizeof u);
	memset(end, -1, sizeof end);
	memset(DP, -1, sizeof DP);
	
	cin >> s >> t;
	n = strlen(s);
	m = strlen(t);
	
	int pre[26];
	memset(pre, -1, sizeof pre);
	for (int i = 0; i < n; i ++)
	{
		memcpy(prev[i], pre, sizeof pre);
		pre[s[i]-'a'] = i;
	}
	
	fill_end();
	
	cout << (f(0, 0)+mod-1)%mod << endl;

	return 0;
}  	
