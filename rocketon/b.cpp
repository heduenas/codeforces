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

char str[1000010];
int ans;
int DP[1010][2];

int f(int idx, int par, char chr) {
	if (str[idx] == 0)
		return 0;
		
	if (DP[idx][par] == -1) {
		DP[idx][par] = f(idx+1, !par, chr);
		if (par == 0 and str[idx] == chr)
			DP[idx][par] = max(DP[idx][par], f(idx+1, 0, chr) + 1);
	}
	return DP[idx][par];
}

int main () {	
	cin >> str;
	for (int i = 0; i < 26; i ++) {
		memset (DP, -1, sizeof DP);
		ans = max(ans, max(f(0, 0, 'A' + i), f(0, 1, 'A' + i)));
	}
	cout << ans << endl;
	
	return 0;
}  	
