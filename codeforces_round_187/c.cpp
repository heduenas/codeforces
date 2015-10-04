#include<stdio.h>
#include<iostream>
using namespace std;

long long n, k, A[1000100], A2[1000010], N;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> A[i];
	}
	
	N = n;
	long long cumsum = 0;
	for (int i = 2, rank = 2; i <= n; i ++) {
		long long cumsum2 = cumsum + (rank - 2) * A2[rank-1];
		long long d = cumsum2 - (rank - 1) * (N-rank) * A[i];
		//printf ("\t%d\n", d);
		if (d < k) {
			cout << i << endl;
			N --;
		} else {
			A2[rank] = A[i];
			rank ++;
			cumsum = cumsum2;
		}
	}
	return 0;
}
