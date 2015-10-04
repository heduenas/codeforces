#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;
int S[100001], A[100010], B[100010];
int I[100001];

int compare (const void *a, const void *b) {
	return ( S[*(int*)a] - S[*(int*)b] );
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &S[i]);
		I[i] = i;
	}
		
	qsort (I, n, sizeof I[0], compare);
	
	bool ans = true;
	for (int i = 0; i < n-2; i ++) {
		if (S[I[i]] == S[I[i+1]]-1 and S[I[i+1]] == S[I[i+2]] -1)
			ans = false;
	}
	
	if (!ans) {
		cout << "NO" << endl;
		return 0;
	}
		
	for (int i = 0; i < n; i ++) {
		A[I[i]] = i;
		if (i < n-1 and S[I[i]] == S[I[i+1]] - 1) {
			A[I[i]] = i+1;
			A[I[i+1]] = i;
			i ++;
		}
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; i ++) {
		printf ("%d ", A[i]);
	}
	cout << endl;
	for (int i = 0; i < n; i ++) {
		printf ("%d ", S[i]-A[i]);
	}
	
	return 0;
}  
