#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, k;
char out[1000010];

int main () {
	cin >> n >> k;
	
	if (n < k or (n > 1 and k == 1)) {
		cout << "-1" << endl;
		return 0;
	}
	
	for (int i = 0; i < n; i ++)
		out[i] = 'a' + (i%2);
			
	for (int i = 0; i < k-2; i ++)
		out[n-i-1] = 'a' + k-i-1;
		
	cout << out << endl;
	
	return 0;
} 
