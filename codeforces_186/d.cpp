#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, k;
int C[311][311];
long long DP[311][311][311];

long long f (int l, int r, int ak) {
	if (ak <= 0)
		return 0;
	if (l > r)
		return -1;
		
	if (DP[l][r][ak] == -1) {
		
	}
	if (DP[l][r][ak] == -2)
		return -1;
	return DP[l][r][ak];
}

int main () {
	memset (C, sizeof C, -1);
	memset (DP, sizeof DP, -1);

	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i ++) {
		int l, r, c;
		scanf ("%d%d%d", &l, &r, &c);
		if (C[l][r] == -1 or C[l][r] > c)
			C[l][r] = c;
	}
	
	cout << f (1, n, k) << endl;

	return 0;
}
