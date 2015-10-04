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

int n;
bool col1[200010];
bool col2[200010];
vector<int> T[200010];
vector<int> A;
bool u[200010];

void dfs(int nd, int odd, int even, int depth) {
	if (u[nd])
		return ;
	u[nd] = 1;
	
	if ((col1[nd] xor ((depth%2)?odd:even)) != col2[nd]) {
		A.push_back(nd);
		if (depth%2)
			odd = !odd;
		else
			even = !even;
	}
	
	for (int i = 0; i < T[nd].size(); i ++) {
		dfs(T[nd][i], odd, even, depth+1);
	}
}

int main () {
	cin >> n;
	for (int i = 0, a, b; i < n-1; i ++) {
		cin >> a >> b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	scan(col1, 1, n+1);
	scan(col2, 1, n+1);
	
	dfs(1, 0, 0, 0);
	cout << A.size() << endl;
	print(A, 0, A.size());

	return 0;
}  	
