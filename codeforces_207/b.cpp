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

int n, m, A[100100][3];
int C[100100];

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i ++)
		scan (A[i], 0, 3);
		
	for (int i = 0; i < m; i ++) {
		int col[4] = {0, 0, 0, 0};
		col[C[A[i][0]]] = 1;
		col[C[A[i][1]]] = 1;
		col[C[A[i][2]]] = 1;
		
		for (int k = 0; k <= 2; k ++) {
			if (C[A[i][k]] == 0)
				for (int z = 1; z <= 3; z ++)
					if (col[z] == 0) {
						col[z] = 1;
						C[A[i][k]] = z;
						break ;
					}
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << C[i] << " ";
	return 0;
}  	
