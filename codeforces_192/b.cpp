#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, A[100100];

struct BIT {
	int data[500000];
	
	void update (int idx, int val) {
		while (idx <= n) {
			data[idx] = max (data[idx], val);
			idx += idx & (-idx);
		}
	}
	int query (int idx) {
		int ret = 1 << 30;
		while (idx) {
			if (ret < data[idx])
				ret = data[idx];
			idx -= idx & (-idx);
		}
		return ret;
	}
} bit;

int main () {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		scanf ("%d\n", &A[i]);
		
	for (int i = 1; i <= n; i ++) {
		bit.update (1, bit.query (1) + 1);
	}

	cout << bit.query (n) << endl;
		
	return 0;
} 
