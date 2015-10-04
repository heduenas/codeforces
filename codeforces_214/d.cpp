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

int n, m, m2;
int ans;
vector<int> G[3010][3];
int L[10010], R[10010];
pair <int, bool> U[20020];

bool u[3010];
void DFS (int nd, int x) {
	if (u[nd])
		return ;
	u[nd] = true;
		
	for (int i = 0; i < G[nd][0].size (); i ++)
		if (G[nd][1][i] <= x and G[nd][2][i] >= x)
			DFS (G[nd][0][i], x);
}

int main () {
	cin >> n >> m;
	m2 = 2 * m;
	for (int i = 0, a, b; i < m; i ++) {
		cin >> a >> b >> L[i] >> R[i];
		a --; b --;
		G[a][0].push_back (b);
		G[a][1].push_back (L[i]);
		G[a][2].push_back (R[i]);
		
		U[2 * i].first = L[i];
		U[2 * i].second = 0;
		U[2 * i + 1].first = R[i];
		U[2 * i + 1].second = 1;
	}
	
	sort (U, U + m2);
	
	int cnt = 0;
	bool prev = false;
	for (int i = 0; i < m2; i ++) {
		if (U[i].second == 0) {
			cnt ++;
			
			memset (u, 0, sizeof u);
			DFS (0, U[i].first);
			if (u[n-1]) {
				ans += U[i+1].first - U[i].first + (prev==false?1:0);
				prev = true;
			} else
				prev = false;
		} else {
			cnt --;
			memset (u, 0, sizeof u);
			if (cnt) {
				DFS (0, U[i].first+1);
				if (u[n-1]) {
					ans += U[i+1].first - U[i].first;
					prev = true;
				}
			} else
				prev = false;
		}
		
	}
	
	if (ans > 0)
		cout << ans << endl;
	else
		cout << "Nice work, Dima!" << endl;
	
	return 0;
}  	
