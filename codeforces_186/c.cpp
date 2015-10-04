#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int npow, n;
int A[2000010];
long long ans;

int main () {
	cin >> npow;
	n = log2 (npow) / 2;
	for (int i = 0; i < npow; i ++)
		scanf ("%d", &A[i]);
		
	sort (A, A + npow);
	ans = (long long)(n+1) * (long long)(A[npow-1]);
	for (int i = 1; i <= n; i ++) {
		for (int j = (1 << 2*(i-1))+1; j <= (1 << (2*i)); j ++) {
			ans += (long long)(n-i+1) * (long long)(A[npow-j]);
		}
	}
	
	cout << ans << endl;

	return 0;
}
