#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

long long n, A[100], p, q, ans, r, s;		// p/q and r/s

long long gcd (long long a, long long b) {
	if (b == 0)
		return a;
	return gcd (b, a % b);
}

int main() {
	cin >> p >> q;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> A[i];
	}
	
	long long g = gcd (p, q);
	p /= g;
	q /= g;
	
	r = A[n-1];
	s = 1;
	for (int i = n-2; i >= 0; i --) {
		g = gcd (r, s);
		r /= g;
		s /= g;
		swap (r, s);
		
		r = A[i] * s + r;
	}
	
	if (p == r and q == s)
		printf ("YES\n");
	else
		printf ("NO\n");
	
	return 0;
}
