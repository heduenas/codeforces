#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, A[510][510], X[100100], F[510][510];
long long ans[100100];

int main () {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			scanf ("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < n; i ++) {
		cin >> X[n-i-1];
		X[n-i-1] --;
	}
	
	for (int k = 1; k < n; k ++) {
		for (int i = 0; i < k; i ++) {
			F[i][k] = A[X[i]][X[k]];
			F[k][i] = A[X[k]][X[i]];
			for (int j = 0; j < k; j ++) {
				if (F[i][j] + A[X[j]][X[k]] < F[i][k])
					F[i][k] = F[i][j] + A[X[j]][X[k]];
				if (F[j][i] + A[X[k]][X[j]] < F[k][i])
					F[k][i] = F[j][i] + A[X[k]][X[j]];
			}
		}
		
		for (int i = 0; i <= k; i ++) {
			for (int j = 0; j <= k; j ++) {
				if (F[i][j] > F[i][k] + F[k][j])
					F[i][j] = F[i][k] + F[k][j];
				ans[k] += (long long)(F[i][j]);
			}
		}
	}
	
	for (int i = n-1; i >= 0; i --)
		cout << ans[i] << " ";
	
	return 0;
}
