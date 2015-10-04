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

const long long mod = 1000000007ll;

int n, k;
char start[2010], end[2010];

int G, B;
long long DPG[200010];
long long DPB[200010];

int main() {
	cin >> start >> end;
	cin >> k;
	n = strlen(start);
	
	strcpy(start+n, start);
	for (int i = 0; i < n; i ++) {
		char tmp = start[i + n];
		start[i+n] = 0;
		if (strcmp(start+i, end) == 0)
			++ G;
		else
			++ B;
		start[i+n] = tmp;
	}
	start[n] = 0;
	
	DPG[0] = 1;
	DPB[0] = 0;
	if (strcmp(start, end) != 0)
		swap(DPG[0], DPB[0]);
		
	for (int i = 1; i <= k; i ++) {
		DPG[i] = (DPG[i-1] * (G-1) + DPB[i-1] * G) % mod;
		DPB[i] = (DPB[i-1] * (B-1) + DPG[i-1] * B) % mod;		
	}
	
	cout << DPG[k] << endl;
	
	return 0;
}
