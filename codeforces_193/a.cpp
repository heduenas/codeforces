#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;
char str[10000];

int main () {
	cin >> n;
	cin >> str;
	
	int len = strlen (str);
	int ans = 0;
	
	for (int i = n; i < len; i += n) {
			if (str[i-1] == str[i-2] and str[i-2] == str[i-3])
				ans ++;
	}
		
	cout << ans << endl;
		
	return 0;
} 
