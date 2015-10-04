#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

const long long mod = 1000000007ll;

long long n, P[2010];
long long DP[2010][2010];
bool U[2010];

long long f (long long blue, long long black) {
	if (blue < 0 or black < 0)
		return 0;

	if (blue == 0 and black == 0)
		return 1;
		
	if (DP[blue][black] == -1) {
		DP[blue][black] = 0;
		
		if (blue) {
			DP[blue][black] += (blue * f (blue-1, black)) % mod;
			DP[blue][black] %= mod;
			if (black) {
				DP[blue][black] += (black * f (blue, black-1)) % mod;
				DP[blue][black] %= mod;
			}
		} else {
			DP[blue][black] += ((black - 1) * f (blue+1, black-2)) % mod;
			DP[blue][black] %= mod;
			DP[blue][black] += (blue * f (blue, black-1)) % mod;
			DP[blue][black] %= mod;
		}
	}
	return DP[blue][black];
}

int main () {
	memset (DP, -1, sizeof DP);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> P[i];
	}
	
	long long blue = 0, black = 0;
	
	for (int i = 1; i <= n; i ++) {
		if (P[i] != -1) {
			U[P[i]] = U[i] = true;
			if (P[P[i]] == -1) {
				blue ++;
			}
		}
	}

	for (int i = 1; i <= n; i ++) {
		if (U[i] == false)
			black ++;
	}
	
	cout << f (blue, black) << endl;
		
	return 0;
} 
