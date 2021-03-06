#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, m, p;
int D[10010], H[10010], T[10010];

int Try (int num) {
	int ret = 0;
	int acum = 0, pl = p, cnt = 0;
	for (int i = 0; i < m; i ++) {
		int j = 1;
		while (i+j-1 < m and T[i] == T[i+j]) {
			j ++;
		}
		
		if ((T[i] >= 0) and (acum + cnt * (T[i] - (i > 0 ? T[i-1] : 0)) > num)) {
			ret += acum;
			acum = 0;
			cnt = 1;
			pl --;
		} else {
			acum += cnt * (T[i] - (i > 0 ? T[i-1] : 0));
			cnt += j;
			i += j-1;
		}
	}
	ret += acum;
	if (cnt > 0)
		pl --;
	if (pl < 0)
		return -1;
	return ret;
}

int main () {
	cin >> n >> m >> p;
	for (int i = 1; i < n; i ++) {
		scanf ("%d", &D[i]);
		D[i] += D[i-1];
	}
	for (int i = 0; i < m; i ++) {
		scanf ("%d", &H[i]);
		scanf ("%d", &T[i]);
		T[i] -= D[H[i]-1];
	}
	
	sort (T, T+m);
	
	int left=0, right=1e7, mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (Try (mid) != -1)
			right = mid;
		else
			left = mid + 1;
	}
	
	cout << Try (left) << endl;
	
	return 0;
}
