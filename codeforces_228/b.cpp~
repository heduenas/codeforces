#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int k;
int n = 120;
char G[150][150];

void conn(int a, int b) {
	a --; b --;
	G[a][b] = G[b][a] = 'Y';
}

int main () {	
	memset(G, 'N', sizeof G);
	cin >> k;
	
	conn(1, 4);
	conn(1, 5);
	
	conn(80 + 31, 2);
	
	for (int i = 0; i < 32; i ++) {
		conn(80 + i, 80 + i + 1);
	}
	
	for (int i = 0; i < 32; i ++) {
		conn(4 + 2 * i, 4 + 2 * (i + 1));
		conn(4 + 2 * i, 4 + 2 * (i + 1) + 1);
		
		conn(4 + 2 * i + 1, 4 + 2 * (i + 1));
		conn(4 + 2 * i + 1, 4 + 2 * (i + 1) + 1);
	}
	
	if (k & 1) {
		conn(1, 80);
	}
	
	for (int i = 1; i < 32; i ++) {
		if (k & (1 << i)) {
			conn(4 + 2 * (i-1), 80 + i);
			conn(4 + 2 * (i-1) + 1, 80 + i);
		}
	}
	
	cout << n << endl;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			printf("%c", G[i][j]);
		}
		printf("\n");
	}

	return 0;
}  	
