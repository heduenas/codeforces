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
int M[1010][1010];

int DP[4][1010][1010];

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> M[i][j];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			DP[0][i][j] = M[i][j];
			if (i == 0 and j == 0)
				continue;
			if (i == 0)
				DP[0][i][j] += DP[0][i][j-1];
			else if (j == 0)
				DP[0][i][j] += DP[0][i-1][j];
			else
				DP[0][i][j] += max(DP[0][i][j-1], DP[0][i-1][j]);				
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = m-1; j >= 0; j --) {
			DP[1][i][j] = M[i][j];
			if (i == 0 and j == m-1)
				continue;
			if (i == 0)
				DP[1][i][j] += DP[1][i][j+1];
			else if (j == m-1)
				DP[1][i][j] += DP[1][i-1][j];
			else
				DP[1][i][j] += max(DP[1][i][j+1], DP[1][i-1][j]);
		}
	}
	
	for (int i = n-1; i >= 0; i --) {
		for (int j = m-1; j >= 0; j --) {
			DP[2][i][j] = M[i][j];
			if (i == n-1 and j == m-1)
				continue;
			if (i == n-1)
				DP[2][i][j] += DP[2][i][j+1];
			else if (j == m-1)
				DP[2][i][j] += DP[2][i+1][j];
			else
				DP[2][i][j] += max(DP[2][i][j+1], DP[2][i+1][j]);
		}
	}
	
	for (int i = n-1; i >= 0; i --) {
		for (int j = 0; j < m; j ++) {
			DP[3][i][j] = M[i][j];
			if (i == n-1 and j == 0)
				continue;
			if (i == n-1)
				DP[3][i][j] += DP[3][i][j-1];
			else if (j == 0)
				DP[3][i][j] += DP[3][i+1][j];
			else
				DP[3][i][j] += max(DP[3][i][j-1], DP[3][i+1][j]);
		}
	}
	
	int ans = 0;
	for (int i = 1; i < n-1; i ++) {
		for (int j = 1; j < m-1; j ++) {
			ans = max(ans, DP[0][i-1][j] + DP[2][i+1][j] + DP[1][i][j+1] + DP[3][i][j-1]);
			ans = max(ans, DP[0][i][j-1] + DP[2][i][j+1] + DP[1][i-1][j] + DP[3][i+1][j]);
		}
	} 
	
	cout << ans << endl;
	
	return 0;
}  	
