#include<stdio.h>
#include<iostream>
using namespace std;

int n, m, N[1000000], cum;

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i < n+1; i ++)
		scanf ("%d", &N[i]);
		
	int t, q, v, x;
	for (int i = 0; i < m; i ++) {
		scanf ("%d", &t);
		if (t == 1) {
			scanf ("%d%d", &v, &x);
			N[v] = x-cum;
		} else if (t == 2) {
			scanf ("%d", &q);
			cum += q;
		} else {
			scanf ("%d", &q);
			printf ("%d\n", N[q] + cum);
		}
	}
	return 0;
}
