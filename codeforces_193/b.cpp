#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, k, ans;
int idx1, idx2;
int A[1000010];
int K[1000010];
int C[1000010];

struct BIT {
	int data[500010];
	BIT () {
		memset (data, 0, sizeof data);
	}
	void update (int idx, int val) {
		while (idx <= n) {
			data[idx] = max(data[idx], val);
			idx += idx & (-idx);
		}
	}
	int query (int idx) {
		int ret = 0;
		while (idx > 0) {
			ret = max(ret, data[idx]);
			idx -= idx & (-idx);			
		}
		return ret;
	}
} bit;

int main () {
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &A[i]);
		C[i] = A[i];
		if (i>1)
			C[i] += C[i-1];
	}
	
	for (int i = k; i <= n; i ++) {
		K[i] = C[i] - C[i-k];
		bit.update (i, K[i]);
	}
		
	for (int i = n; i >= k; i --) {
		if (K[i] + bit.query (i-k) >= ans) {
			ans = K[i] + bit.query (i-k);
			idx2 = i-k+1;
		}
	}
	
	for (idx1 = k; idx1 < idx2; idx1 ++)
		if (K[idx2+k-1] + K[idx1] == ans) {
			idx1 -= k-1;
			break ;
		}
	
	cout << idx1 << " " << idx2 << endl;
		
	return 0;
} 
