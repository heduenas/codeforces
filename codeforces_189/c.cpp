#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const long long mod = 1000000007;

long long mod_pow (long long num, int pow) {
	long long ret = 1;
	for (int i = 0; i <= 31; i ++) {
		if (pow & (1 << i))
			ret = (ret * num) % mod;
		num = (num * num) % mod;
	}
	return ret;
}


int n;
char str[1010];
long long ans;

int main () {
	cin >> str;
	n = strlen (str);
	
	for (int i = 1; i <= n; i ++) {
		if (str[n-i] == '1') {
			ans += mod_pow (2, i-2+n);
			ans %= mod;
		}
	}
	
	cout << ans << endl;

	return 0;
}
