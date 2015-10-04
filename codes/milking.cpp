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

int n;
int A[400100];
long long ans;

int main () {
	cin >> n;
	scan(A, 0, n);
	
	long long count = 0;
	for (int i = 0; i < n; i ++)
	{
		if (A[i] == 0)
		{
			ans += count;
		}
		else
		{
			count ++;
		}
	}
	count = 0;
	for (int i = n-1; i >= 0; i --)
	{
		if (A[i] == 1)
		{
			ans += count;
		}
		else
		{
			count ++;
		}
	}
	
	cout << ans/2 << endl;

	return 0;
}  	
