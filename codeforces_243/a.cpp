#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<list>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int n, k;
int A[500];
int B[500];
int C[500];
int ans = -99999999;

int main () {
	cin >> n >> k;
	scan(A, 0, n);
	
	memcpy(B, A, sizeof A);
	
	for (int i = 0; i < n; i ++) {
		int sum = 0, sum2;
		for (int j = i; j < n; j ++) {
			sum += A[j];
			sum2 = sum;
			
			int len = i + n - j - 1;
			memcpy(B, A, sizeof(int) * (i+1));
			memcpy(B+(i), A+(j+1), sizeof(int) * (n-j-1));
			sort(B, B+len);
			reverse(B, B+len);
			
			int len2 = j-i+1;
			memcpy(C, A + i, sizeof(int) * (j-i+1));
			sort(C, C+len2);
			
			for (int z = 0; z < len2 and z < len and z < k; z ++)
				if (B[z] > C[z])
					sum2 += B[z] - C[z];
				
			if (ans < sum2)
				ans = sum2;
		}
	}
   
   	cout << ans << endl;
   
    return 0;
}   
