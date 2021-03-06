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

int n, m;
vector<int> G[50010], H[50010];

int A[2][50010];

long long ans;

int u[50010];
int DFS(int nd, int depth, vector<int> M[], int aidx)
{
	if (u[nd] != -1)
		return nd;
		
	A[aidx][nd] = max(A[aidx][nd], depth);
		
	u[nd] = depth;

	int ret = nd;

	for (int i = 0; i < M[nd].size(); i ++)
	{
		int opt = DFS(M[nd][i], depth + 1, M, aidx);
		if (u[opt] > u[ret])
			ret = opt;
	}
	
	return ret;
}

int main () {
	cin >> n >> m;
	
	for (int i = 0, a, b; i < n-1; i ++) 
	{
		cin >> a >> b;
		a --; b --;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 0, a, b; i < m-1; i ++) 
	{
		cin >> a >> b;
		a --; b --;
		H[a].push_back(b);
		H[b].push_back(a);
	}

	memset(u, -1, sizeof u);
	int nd0 = DFS(0, 0, G, 0);
	memset(u, -1, sizeof u);
	int nd1 = DFS(nd0, 0, G, 0);
	memset(u, -1, sizeof u);
		DFS(nd1, 0, G, 0);

	memset(u, -1, sizeof u);
	nd0 = DFS(0, 0, H, 1);
	memset(u, -1, sizeof u);
	nd1 = DFS(nd0, 0, H, 1);
	memset(u, -1, sizeof u);
		DFS(nd1, 0, H, 1);
	
	sort(A[0], A[0] + n);
	sort(A[1], A[1] + m);
	
	int minsize = max(A[0][n-1], A[1][m-1]);
	long long cumsum = 0;
	long long right = 0;
	for (int i = 0, j = m-1; i < n; i ++)
	{
		while (j >= 0 and A[0][i] + 1 + A[1][j] >  minsize)
		{
			cumsum += A[1][j];
			right ++;
			j --;
		}
		ans += cumsum + (long long)(A[0][i] + 1) * right;
		ans += (m - right) * minsize;
	}
	
	printf("%.3lf\n", (double)(ans) / (double)(n * m));
	
	//cout << (double)(ans) / (double)(n * m) << endl;
	
	return 0;
} 
