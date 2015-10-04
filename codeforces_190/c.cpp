#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n;
vector<int> G[100100];

int main () {
	cin >> n;
	for (int i = 0, a, b; i < n; i ++) {
		scanf ("%d%d", &a, &b);
		a --; b --;
		G[a].push_back (b);
	}
	
	return 0;
}
