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

struct Node {
	int C[3];
} trie[20000100];
int ndc = 1;

void insert (int nd, char str) {
	if (trie[nd].C[str-'a'] == 0)
		trie[nd].C[str-'a'] = ndc ++;
}

int n;
char T[21][21];

bool DP[21][21][50][50];

void F (int y, int x, int nd, int ac=0, int bc=0) {
	if (DP[y][x][ac][bc] == true)
		return ;
	DP[y][x][ac][bc] = true;
	
	if (y >= n or x >= n)
		return ;
	
	insert (nd, T[y][x]);
	F (y+1, x, trie[nd].C[T[y][x]-'a'], ac + (T[y][x] == 'a'), bc + (T[y][x] == 'b'));
	F (y, x+1, trie[nd].C[T[y][x]-'a'], ac + (T[y][x] == 'a'), bc + (T[y][x] == 'b'));
}

int Game (bool turn, int nd, int ac = 0, int bc = 0) {	
	int ans = -1;
	for (int i = 0; i < 3; i ++) {
		if (trie[nd].C[i] == 0)
			continue ;
			
		int res = Game (!turn, trie[nd].C[i], ac + (i == 0), bc + (i == 1));
		if ((ans == -1) or ((ans == 2 or ans == !turn) and res == turn) or ((ans == !turn) and res == 2))
			ans = res;
	}
	if (ans == -1) {
		if (ac > bc)
			return 0;
		if (bc > ac)
			return 1;
		else
			return 2;
	}
	return ans;
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> T[i];
		for (int j = 0; j < n; j ++)
			if (T[i][j] > 'c')
				T[i][j] = 'c';
	}
	
	/*for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			F (i, j, 0);*/
	F (0, 0, 0);
	
	int ans = Game (0, 0);
	if (ans == 0)
		cout << "FIRST" << endl;
	else if (ans == 1)
		cout << "SECOND" << endl;
	else
		cout << "DRAW" << endl;
	return 0;
}  	
