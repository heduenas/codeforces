#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, A[1000], m, B[1000];

int main () {
	cin >> n;
	m = 2 * n -1;
	for (int i = 0; i < m; i ++) {
		cin >> A[i];
		B[i] = A[i];
	}
		sort (A, A + m);
		for (int i =0; i < n; i ++)
			A[i] *= -1;

	while (1) {
		sort (A, A + m);
		if (A[0] + A[1] < 0) {
			A[0] *= -1;
			A[1] *= -1;
		} else
			break ;
	}
	
	int ans = 0;
	for (int j = 0; j < m; j++)
		ans += A[j];
		
		

	while (1) {
		sort (B, B + m);
		if (B[0] + B[1] < 0) {
			B[0] *= -1;
			B[1] *= -1;
		} else
			break ;
	}
	
	int ansb = 0;
	for (int j = 0; j < m; j++)
		ansb += B[j];
		
		
	cout << max(ans, ansb) << endl;
	
	return 0;
}
