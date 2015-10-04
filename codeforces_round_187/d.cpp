#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char a[200], c[200];
int la, lc;
int b, d, ans;
int DP[200][200];

int f(int pos1, int pos2) {
	if (pos2 == lc)
		return 1;
	if (DP[pos1][pos2] == 0) {
		if (a[pos1] != c[pos2])
			DP[pos1][pos2] = -1;
		else {
			DP[pos1][pos2] = f ((pos1+1)%la, (pos2+1));
		}
	}
	return DP[pos1][pos2]==1?1:0;
}

int main() {
	scanf ("%d", &b, &d);
	scanf ("%s%s", a, c);
	la = strlen (a);
	lc = strlen (c);
	
	int tot = 0;
	for (int i = 0; i < la*b - lc * d; i ++) {
		bool valid = true;
		for (int j = 0; j < d; j ++) {
			if (f((i + lc * j)%la, 0) == false) {
				valid = false;
				break ;
			}
		}
		if (valid == true) {
			i += lc * d-1;
			ans ++;
		}
	}
	printf ("%d\n", ans);
	return 0;
}
