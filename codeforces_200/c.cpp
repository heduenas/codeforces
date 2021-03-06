#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

long long n, m;
long long h[100100], p[100100];

bool f (long long time) {
	long long i = 0, j = 0;
	while (i < n and j < m) {
		if (p[j] > h[i]) {
			while (j < m and h[i]+time >= p[j])
				j ++;
		} else {
			if (h[i] - time > p[j])
				return false;
			long long ak = max (p[j] + time - (h[i] - p[j]), h[i] + (time - (h[i] - p[j]))/2ll );
			
			while (j < m and ak >= p[j])
				j ++;
		}
		
		i ++;
	}
	
	return j >= m;	
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> h[i];
	}
	for (int i = 0; i < m; i++)
		cin >> p[i];
		
	long long l = 0, r = 200000000000ll, m;
	while (l < r) {
		m = (l + r) / 2ll;
		if (f (m))
			r = m;
		else
			l = m + 1;
	}
	
	cout << l << endl;

	return 0;
} 
