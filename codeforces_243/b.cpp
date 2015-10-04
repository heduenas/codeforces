#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<list>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int n, m, k;
bool A[110][110];

bool T[110];
int ans = 11;


int Try() {
	int ret = 0;
	for (int col = 0; col < m; col ++) {
		int opt1 = 0, opt2 = 0;
		for (int row = 0; row < n; row ++) {
			opt1 += A[row][col] != T[row];
			opt2 += A[row][col] == T[row];
		}
		ret += min(opt1, opt2);
	}
	return ret;
}

int main () {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (n <= m)
				cin >> A[i][j];
			else
				cin >> A[j][i];
	if (n > m)
		swap(n, m);
		
	if (k >= n) {
		for (int i = 0; i < (1 << n); i ++) {
			for (int z = 0; z < n; z ++)
				T[z] = (i & (1 << z)) > 0;
				
			//memset(DP, -1, sizeof DP);
			int opt = Try();
			ans = min(opt, ans);
		}
	} else {
		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < n; j ++)
				T[j] = A[j][i];
			//memset(DP, -1, sizeof DP);
			int opt = Try();
			ans = min(opt, ans);
		}
	}
	
	if (ans > k)
		ans = -1;
	cout << ans << endl;
   
    return 0;
}   
