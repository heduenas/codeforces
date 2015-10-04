#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int n = 100000-1;

int main () {
	cout << n << endl;
	cout << n << " ";
	for (int i = 1; i <= n-1; i += 2) {
		printf ("%d %d ", i+1, i);
	}

	return 0;
}
