#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, m;
char A[10010], B[10010];

int main () {
	cin >> A >> B;
	n = strlen (A);
	m = strlen (B);
	
	int onesa = 0;
	for (int i = 0; i < n; i ++)
		if (A[i] == '1')
			onesa ++;
			
	int onesb = 0;
	for (int i = 0; i < m ; i ++)
		if (B[i] == '1')
			onesb ++;
	
	if (onesa % 2 == 1)
		onesa ++;
		
bool	ans = onesa >= onesb;
	
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl ;
	
	return 0;
} 
