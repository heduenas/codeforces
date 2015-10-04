#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

long long n, A[1000000], ans;

int main () {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> A[i];
		ans += A[i];
	}
	
	sort (A, A + n);
	
	cout << max (A[n-1], (ans + n-2) / (n-1)) << endl;
	
	return 0;
} 
