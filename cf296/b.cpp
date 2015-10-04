#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) ((1ll) << (_z))
using namespace std;

int n;
pair<int, int> X[400100];
map<int, int> M;
int diffs[400100], dc;

struct BIT {
	int data[500010];
	BIT () {
		memset (data, -1, sizeof data);
	}
	void update (int idx, int val) {
		while (idx <= 500010) {
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
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> X[i].first >> X[i].second;
		diffs[dc ++] = X[i].first - X[i].second;
		diffs[dc ++] = X[i].first + X[i].second;
	}

	sort(diffs, diffs + dc);
	for (int i = 0; i < dc; i ++)
	{
		M[diffs[i]] = i;
	}

	sort(X, X + n);
	for (int i = 0; i < n; i ++)
	{
		bit.update(M[X[i].first + X[i].second], bit.query(M[X[i].first - X[i].second]) + 1);
		//cout << "update " << M[X[i].first + X[i].second] << " " << bit.query(M[X[i].first - X[i].second]) + 1 << endl;
		//print(bit.data, 0, 10);
		//cout << endl;
	}
	
	cout << bit.query(M[X[n-1].first + X[n-1].second]) << endl;
	//print(bit.data, 0, 10);
	//cout << endl;

	return 0;
}  	
