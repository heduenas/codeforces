#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int p, P[5000];

double T, n, ans;
double A[3000010];
double B[3000010];

int main () {
	scanf ("%d", &p);
	for (int i = 0; i < p; i ++)
		cin >> P[i];
		
	T = ((p-1) * (p)) / 2;

	for (int i = 0; i < p; i ++) {
		for (int j = i+1; j < p; j ++) {
			if (P[i] > P[j])
				n ++;
		}
	}
	
	if (n == 0)
		ans = 0;
	else if (T == 1)
		ans = 1;
	else {
		//ans = n * (T - n) + (n / T) * ((T / (T-1.0)) * T);
		ans = ((int)n % 2) + 4 * ((int)n / 2);
	}
	
	printf ("%.6lf\n", ans);
	
	return 0;
} 
