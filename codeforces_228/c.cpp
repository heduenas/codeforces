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

int n, S[200], A[200][200], sum, me;
vector<int> odd;

int main () {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> S[i];
		for (int j = 0; j < S[i]; j ++) {
			cin >> A[i][j];
			sum += A[i][j];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < S[i] / 2; j ++) {
			me += A[i][j];
		}
		if (S[i] % 2 == 1)
			odd.push_back(A[i][S[i] / 2]);
	}
	
	sort(odd.begin(), odd.end());
	reverse(odd.begin(), odd.end());
	for (int i = 0; i < odd.size(); i += 2)
		me += odd[i];
		
	cout << me << " " << sum - me << endl;
	
	return 0;
}  	
