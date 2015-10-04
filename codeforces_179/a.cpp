#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, m, k;
int N[100100];
int L[100100], R[100100];
long long D[100100];

int A[100100];
long long B[100100];

int main () {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i ++)
		scanf ("%d", &N[i]);
	for (int i = 0; i < m; i ++) {
		scanf ("%d%d%d", &L[i], &R[i], &D[i]);
	}
	for (int i = 0; i < k; i ++) {
		int x, y;
		scanf ("%d%d", &x, &y);
		A[x-1] ++;
		A[y] --;
	}
	
	long long cnt = 0;
	for (int i = 0; i < m; i ++) {
		cnt += A[i];
		B[L[i]-1] += cnt * D[i];
		B[R[i]] -= cnt * D[i];
	}
	
	long long acum = 0;
	for (int i = 0;  i< n; i ++) {
		acum += B[i];
		cout << (long long)(N[i]) + acum << " ";
	}	
	
	return 0;
}
