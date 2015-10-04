#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

int n, A[100], zeroes, ans, ans_arg;
int B[2][2][2];

void Add (int a) {
	bool b1, b2, b3;
	
	b3 = a%10 > 0;
	b2 = (a/10)%10 > 0;
	b1 = (a/100) > 0;
	
	B[b1][b2][b3] = a;
}

void Test (int comb) {
	int bits = 0;	
	for (int i = 0; i < 8; i ++) {
		if ((comb & (1 << i)) == 0)
				continue;
		
		if (B[(i&4) > 0][(i&2) > 0][(i&1) > 0] == 0)
			return;
		
		bits ++;
		for (int j = i+1; j < 8; j ++) {
			if ((comb & (1 << j)) == 0)
				continue;
				
			for (int k = 0; k < 3; k ++) {
				
				if (((i & (1 << k)) > 0) and ((j & (1 << k)) > 0)) {
					return ;
				}
			}
		}
	}
	
	if (bits > ans) {
		ans = bits;
		ans_arg = comb;
	}
}

void print_arg (int comb) {

	for (int i = 0; i < 8; i ++) {
		if ((comb & (1 << i)) == 0)
				continue;
		
		if (B[(i&4) > 0][(i&2) > 0][(i&1) > 0] == 0)
			return;
		
		printf ("%d ", B[(i&4) > 0][(i&2) > 0][(i&1) > 0]);
	}
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &A[i]);
		if (A[i] == 0)
			zeroes ++;
		else
			Add (A[i]);
	}
	
	for (int comb = 0; comb < (1 << 8); comb ++) {
		Test (comb);
	}
	ans += zeroes;
	
	printf ("%d\n", ans);
	for (int i = 0; i < zeroes; i ++)
		printf ("%d ", 0);
	print_arg (ans_arg);
	
	return 0;
}
