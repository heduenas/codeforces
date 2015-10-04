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
int V[100100][3], H[100100][3];
int ans;

int main () {	
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < 3; j ++)
			cin >> V[i][j];
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < 3; j ++)
			cin >> H[i][j];
			
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int int_x = V[i][0];
			int int_y = H[j][1];
			int opt = min(int_x - H[j][0], H[j][0] + H[j][2] - int_x);
				opt = min(opt, min(int_y - V[i][1], V[i][1] + V[i][2] - int_y));
			ans = max(opt, ans);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
