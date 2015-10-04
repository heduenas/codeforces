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

#define Forth(n_) (10000 + n_)
#define Back(n_) (n_ - 10000)

int n, k;
int A[110], B[110], C[110];
int DP[110][20010];

int main () {
	cin >> n >> k;
	scan (A, 0, n);
	scan (B, 0, n);
	
	for (int i = 0; i < n; i ++)
		B[i] *= k;
		
	for (int i = 0; i < n; i ++)
		C[i] = A[i] - B[i];
		
	memset (DP, -1, sizeof DP);
	
	DP[0][Forth (0)] = 0;
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= Forth (10000); j ++) {
			if (DP[i][j] != -1) {
				if (DP[i+1][j] == -1 or DP[i+1][j] < DP[i][j])
					DP[i+1][j] = DP[i][j];
				if (Back (j) + C[i] >= -10000) {
					if (DP[i+1][Forth (Back (j) + C[i])] < DP[i][j] + A[i])
						DP[i+1][Forth (Back (j) + C[i])] = DP[i][j] + A[i];
				}
			}
		}
	}
	
	if (DP[n][Forth (0)] == 0)
		cout << -1 << endl;
	else
		cout << DP[n][Forth (0)] << endl;
	
	
	return 0;
}  	
