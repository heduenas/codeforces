#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;
long long DP[2][200010];
int A[200010];

long long f (int idx, bool dir) {
	if (idx > n or idx <= 0)
		return 0;
	if (idx == 1)
		return -2;
	if (DP[dir][idx] == -1) {
	
		DP[dir][idx] = -3;
		
		long long ret = f(idx + (dir?A[idx]:-A[idx]), !dir);
		
		if (ret == -3 or ret == -2)
			DP[dir][idx] = -2;
		else
			DP[dir][idx] = ret + (long long)(A[idx]);
	}
	return DP[dir][idx];
}

int main () {
	cin >> n;
	for (int i = 2; i <= n; i ++)
		scanf ("%d", &A[i]);
	
	memset (DP, -1, sizeof DP);
	
	for (int i = 1; i < n; i ++) {
		if (f (1+i, 0) == -2)
			cout << -1 << endl;
		else
			cout << f (1 + i, 0) + (long long)(i) << endl;
	}

	return 0;
} 
