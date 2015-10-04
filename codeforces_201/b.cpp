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
using namespace std;

int len_s1, len_s2, len_virus;
char s1[210], s2[210], virus[210];
int P[201][256];
int DP[110][110][110];
int DPo[110][110][110];

void init () {
	for (int i = 0; i < len_virus; i ++) {
		for (int l = 'A'; l <= 'Z'; l ++) {
			int j = i;
			for (j = i; j >= 0; ) {
			
				bool valid = true;
						
				for (int k = 0; k < j; k ++) {
					if (virus[k] != virus[i-j+k])
						valid = false;
				}
						
				if (l != virus[j])
					valid = false;
					
				if (valid)
					break ;
				else
					j --;
					
			}
			P[i][l] = j;
		}
	}
}

int f (int pos1, int pos2, int posv) {
	if (posv == len_virus)
		return - (1 << 24);
	if (pos1 == len_s1 or pos2 == len_s2)
		return 0;		
		
	if (DP[pos1][pos2][posv] == -1) {
		DP[pos1][pos2][posv] = 0;
		int opt = 0, arg = 0;
		if (f (pos1 + 1, pos2, posv) > opt) {
			opt = f (pos1 + 1, pos2, posv);
			arg = 0;
		}
		if (f (pos1, pos2+1, posv) > opt) {
			opt = f (pos1, pos2+1, posv);
			arg = 1;
		}
		if (s1[pos1] == s2[pos2] and f (pos1+1, pos2+1, P[posv][s1[pos1]]+1) +1> opt) {
			opt = f (pos1+1, pos2+1, P[posv][s1[pos1]]+1)+1;
			arg = 2;
		}
		DP[pos1][pos2][posv] = opt;
		DPo[pos1][pos2][posv] = arg;
	}
	return DP[pos1][pos2][posv];
}

int main () {
	cin >> s1 >> s2 >> virus;
	len_s1 = strlen (s1);
	len_s2 = strlen (s2);
	len_virus = strlen (virus);
	
	init ();
	memset (DP, -1, sizeof DP);
	
	if (f (0, 0, 0) <= 0)
		cout << 0 << endl;
	else {
		int pos1 = 0, pos2 = 0, posv = 0;
		while (pos1 < len_s1 and pos2 < len_s2) {
			if (DPo[pos1][pos2][posv] == 0)
				pos1 ++;
			else if (DPo[pos1][pos2][posv] == 1)
				pos2 ++;
			else {
				cout << s1[pos1];
				posv = P[posv][s1[pos1]]+1;
				pos1 ++;
				pos2 ++;
			}
		}
		cout << endl;
		//cout << f (0, 0, 0) << endl;
	}
	
	return 0;
} 
