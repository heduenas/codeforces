#include<stdio.h>

int n, N[100000], ans;
int A[100000], O[100000];

int main() {
	scanf ("%d", &n);
	for (int i = 0, a, b; i < n; i ++) {
		scanf ("%d%d", &a, &O[i]);
		A[i] = a;
		ans ++;
	}
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++) {
			if (i == j)
				continue ;
			if (O[i] == A[j]) {
				ans --;
				A[j] = -1;
			}
		}
	printf ("%d\n", ans);
	return 0;
}
