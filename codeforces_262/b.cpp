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

long long a, b, c;
vector<long long> ans;

long long S(long long x) {
	long long ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

long long G(long long s) {
	long long ret = b * s;
	for (int i = 1; i < a; i ++)
		ret *= s;
	ret += c;
	return ret;
}

int main () {
	cin >> a >> b >> c;

	for (long long s = 1; s <= 81; s ++) {
		if ( G(s) > 0 and G(s) < 1000000000 and G(S(G(s))) == G(s) )
			ans.push_back(G(s));
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i ++)
		cout << ans[i] << " ";

	return 0;
}  	
