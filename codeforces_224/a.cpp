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

char s[1000010];
char r[1000010];
int nl, nr, m;

int main () {	
	cin >> s;
	int i = 0; 
	while (s[i] and s[i] != '|')
		i ++;
	nl = i ++;
	while (s[i] and s[i] != '|')
		i ++;
	nr = i-1-nl;
	cin >> r;
	m = strlen (r);
	
	if (	(nr + nl + m)%2 == 1	or
			max(nr, nl) > min(nr,nl) + m	)
		cout << "Impossible" << endl;
	else {
		for (int j = 0; j < nl; j ++)
			printf ("%c", s[j]);
		int k = 0;
		for (; k < (nr+nl+m)/2 - nl; k ++)
			printf ("%c", r[k]);
		
		printf ("|");
		
		for (int j = nl+1; j < nl+nr+1; j ++)
			printf ("%c", s[j]);
		for (; r[k]; k ++)
			printf ("%c", r[k]);
		printf ("\n");
	}

	return 0;
}  	
