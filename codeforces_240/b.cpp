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

const long long mod  = 1000000007;

long long DP[2100][2100];

int k;

vector<int> D[2100];

long long f(int n, int ka) {
	if (ka == 0)
		return 1;
		
	if (DP[n][ka] == -1) {
		DP[n][ka] = 0;
		if (k == ka)
			for (int i = n; i > 0; i --) {
				DP[n][ka] += f(i, ka-1);
				DP[n][ka] %= mod;
			}
		else
			for (int i = 0; i < D[n].size(); i ++) {
				DP[n][ka] += f(D[n][i], ka-1);
				DP[n][ka] %= mod;
			}
	}
//	cout << n << " " << ka << ": " << DP[n][ka] << endl;
	return DP[n][ka];
}

int n;

int main () {
	for (int i = 1; i < 2100; i ++)
		for (int j = i; j < 2100; j += i)
			D[j].push_back(i);

	memset(DP, -1, sizeof DP);
	cin >> n >> k;
	
	cout << f(n, k) << endl;

	return 0;
}  	
