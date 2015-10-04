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

struct BITM {
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
};

struct BITm {
	int data[500010];
	BIT () {
		memset (data, -1, sizeof data);
	}
	void update (int idx, int val) {
		while (idx <= 500010) {
			data[idx] = min(data[idx], val);
			idx += idx & (-idx);
		}
	}
	int query (int idx) {
		int ret = 0;
		while (idx > 0) {
			ret = min(ret, data[idx]);
			idx -= idx & (-idx);			
		}
		return ret;
	}
};

struct 

int main () {
	cin >> w >> h >> n;
	for (int i = 0; i < )

	return 0;
}  	
