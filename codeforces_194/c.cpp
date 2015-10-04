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
pair<int, pair<int, int> > A[1000010];
int C[2][1000010];
int f1, f2;

int main () {
	cin >> n >> m;
	
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			scanf ("%d", &A[cnt].first);
			A[cnt].second.first = i;
			A[cnt].second.second = j;
			
			cnt ++;
		}
	}
	
	sort (A, A + cnt);
	
	for (int i = cnt - 1; i >= 0; i --) {
		C[0][A[i].second.first] ++;
		C[1][A[i].second.second] ++;
		if (C[0][A[i].second.first] == 2)
			f1 ++;
		if (C[1][A[i].second.second] == 2)
			f2 ++;
		if (f1 >= 2 and f2 >= 2) {
			cout << A[i].first << endl;
			return 0;
		}
	}

	return 0;
} 
