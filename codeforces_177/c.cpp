#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n; long long ans;
int A[1000010];

int most (int a) {
	for (int i = 30; i >= 0; i --)
		if (a & (1 << i))
			return 1 << i;
}

int main () {
	cin >> n;
	memset (A, -1, sizeof A);
	
	for (int i = n; i >= 0; i --) {
		if (A[i] == -1) {
			A[i] = 0;
			if (i != 0) {
				A[i] = i ^ ((most(i) << 1) - 1);
				A[A[i]] = i;
			} 
		
		}
		ans += (long long)(A[i] ^ i);
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i ++) {
		printf ("%d ", A[i]);
	}
	
	return 0;
} 
