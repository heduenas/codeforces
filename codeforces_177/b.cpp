#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, k;
const int mod = 1000000007;
long long ans;
int P[8];

int BF (int p) {
	if (p == k) {
		for (int i = 0; i < k; i ++) {
			int p = i;
			for (int j = 0; j < k; j ++) {
				if (p == 0)
					break;
				p = P[p];
			}
			if (p != 0)
				return 0;
		}
		ans ++;
		return 1;
	}
	for (int i = 0; i < k; i ++) {
		P[p] = i;
		BF (p+1);
	}
}

int main () {
	cin >> n >> k;
	
	BF (1);
	ans %= mod;
	ans *= k;
	ans %= mod;
	
	for (int i = 0; i < n-k; i ++) {
		ans *= n-k;
		ans %= mod;
	}
	
	cout << ans << endl;
	
	return 0;
} 	
