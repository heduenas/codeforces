#include<stdio.h>

int n, B[110], m, x, y;

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf ("%d", &B[i]);
	
	scanf ("%d", &m);	
	for (int i = 0; i < m; i ++) {
		scanf ("%d%d", &y, &x);
		if (y-2 >= 0)
			B[y-2] += x-1;
		B[y] += B[y-1] - x;
		B[y-1] = 0;
	}
	
	for (int i = 0; i < n; i ++)
		printf ("%d\n", B[i]);
	return 0;
}
