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
char str[100010];

char st[100010];
int ss;

int main () {
	cin >> str;
	n = strlen (str);
	
	for (int i = 0; i < n; i ++) {
		if (ss and st[ss-1] == str[i])
			ss --;
		else
			st[ss++] = str[i];
	}
	
	if (ss == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	
	return 0;
} 
