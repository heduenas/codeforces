#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, d, A[1000];
int X[1000], Y[1000];

int C[1000];
bool u[1000];

int dist (int a, int b) {
	return abs (X[a]-X[b]) + abs (Y[a]-Y[b]);
}

int main () {
	cin >> n >> d;
	for (int i =1; i < n-1; i ++)
		cin >> A[i];
	for (int i =0; i < n; i ++)
		cin >> X[i] >> Y[i];
		
	for (int i = 0; i < n-1; i ++)
		C[i] = 1 << 30;
		
	for (int z = 0; z < n; z ++) {
		int a = -1;
		for (int i = 0; i < n; i ++) {
			if (!u[i] and (a == -1 or C[i] < C[a]))
				a = i;
		}
		u[a] = true;
		
		for (int b = 0; b < n; b ++) {
			if (b == a)
				continue ;
				
			if (C[b] > max (0, C[a] + d * dist(a, b) - A[b]))
				C[b] = max (0, C[a] + d * dist(a, b) - A[b]);
		}
	}
	
	cout << C[0] << endl	;
	
	return 0;
}
