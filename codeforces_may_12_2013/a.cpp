#include<stdio.h>
#include<math.h>

int n, ans;

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			int s = i*i + j*j;
			int sr = sqrt(s);
			if (sr > n)
				break ;
			
			if (s == sr * sr)
				ans ++;	
		}
	}
	
	printf ("%d\n", ans);
	
	return 0;
}
