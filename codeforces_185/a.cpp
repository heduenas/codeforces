#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, k;

int main () {
	cin >> n >> k;
	
	if ((n * (n-1))/2 <= k)
		printf ("no solution\n");
	else
		for (int i = 0; i < n; i ++) {
			printf ("%d %d\n", i, (n + 1) * i);
		}
	
	return 0;
}
