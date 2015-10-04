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
int Q[1000010], qc = 1;
double A[1000010];
double prom;

int main () {
	cin >> n;
	
	double b, c;
	int a;
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &a);
		if (a == 1) {
			scanf ("%lf%lf", &b, &c);
			A[(int)(b)-1] += c;
			prom += (b * c) / (double)(qc);
		} else if (a == 2) {
			scanf ("%lf", &b);
			prom = ((prom * (double)(qc)) + b) / ((double)(qc) + 1);
			Q[qc ++] = b;
		} else {
			prom = ((prom * (double)(qc)) - (double)(Q[qc-1]+A[qc-1])) / ((double)(qc) - 1);
			
			A[qc-2] += A[qc-1];
			A[qc-1] = 0;
			
			qc --;
		}
		//cout << prom << endl;
		printf ("%.6lf\n", prom);
	}

	return 0;
} 
