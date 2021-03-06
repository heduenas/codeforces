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
double A[5000], B[5000];
double sum;
int count0, count1;
int min0, max0;

int main () {
	cin >> n;
	for (int i = 0; i < 2*n; i ++) {
		cin >> A[i];
		
		B[i] = A[i] - (int)(A[i]);
		sum += B[i];
		if (B[i] > 0)
			count0 ++;
		else
			count1 ++;
	}
	
	min0 = max (0, n - count1);
	max0 = min (count0, n);
	
	double ans;
	
	if (sum - (int)(sum) <= 0.5 and sum >= min0 and sum - (int)(sum) <= max0) {
		ans = sum - (int)(sum);
	} else if ((int)(sum+1.0) - sum <= 0.5 and sum+1.0 >= min0 and (int)(sum+1.0) <= max0) {
		ans = (int)(sum+1.0) - sum;
	} else
		ans = min (fabs (sum - min0), fabs (sum-max0));
		
	printf ("%.3lf\n", ans);
	
	return 0;
} 
