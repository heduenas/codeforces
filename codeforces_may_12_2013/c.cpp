#include<stdio.h>
#include<math.h>

int n;

int main() {
	scanf ("%d", &n);
	
	if (n % 2 == 0) {
		printf ("-1\n");
		return 0;
	}
	
	for (int j = 0; j < 2; j ++) {
		for (int i = 0; i < n; i ++)
			printf ("%d ", i);
		printf ("\n");	
	}
	for (int i = 0; i < n; i ++)
		printf ("%d ", (2*i) % n);
	printf ("\n");
			
		
	return 0;
}
