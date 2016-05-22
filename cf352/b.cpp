#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <cassert>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>      // std::setprecision

#define deb(x) cout << #x << " = " << x << endl;
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;

int n, k;
int C[1000100];
long long sum;
long long avgfloor, avgceil;

long long f1(long long cut) {
	long long ret = 0;
	for (int i = n-1; i >= 0; i --) {
		if (C[i] <= cut)
			break;
		ret += C[i] - cut;
	}
	return ret;
}

long long bs1() {
	long long l = avgceil, r = C[n-1], m;
	while (l < r) {
		m = (l + r) / 2;
		if (f1(m) > k) {
			l = m+1;
		} else {
			r = m;
		}
	}
	return l;
}

long long f2(long long cut) {
	long long ret = 0;
	for (int i = 0; i < n; i ++) {
		if (C[i] >= cut)
			break;
		ret += cut - C[i];
	}
	return ret;
}

long long bs2() {
	long long l = 0, r = avgfloor, m;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (f2(m) <= k) {
			l = m;
		} else {
			r = m-1;
		}
	}
	return l;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &C[i]);
		sum += C[i];
	}
	sort(C, C+n);

	avgfloor = sum / n;
	avgceil = (sum + n - 1) / n;

	long long high = bs1();
	long long low = bs2();

	cout << high - low << endl;

	return 0;
}

