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

int n, m, k, k2;
char A[1010][1010];
bool u[1010][1010];

void dfs (int y, int x) {
	if (u[y][x] or A[y][x] != '.')
		return ;
	u[y][x] = true;
	
	dfs (y-1, x);
	dfs (y+1, x);
	dfs (y, x-1);
	dfs (y, x+1);
	
	if (k2) {
		A[y][x] = 'X';
		k2 --;
	}
}

int main () {
	cin >> n >> m >> k;
	k2 = k;
	
	for (int i = 1; i <= n; i ++)
		cin >> A[i]+1;
		
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (A[i][j] == '.') {
				dfs (i, j);
				break ;
			}
			
	for (int i = 1; i <= n; i ++)
		cout << A[i]+1 << endl;
	
	return 0;
}  	
