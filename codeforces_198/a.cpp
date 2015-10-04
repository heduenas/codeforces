#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int  n;
char A[1100][1100];
bool B[1100][1100];

int FillA () {
	int ret = 0;
	memset (B, 0, sizeof B);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (A[i][j] == '.') {
				B[i][j] = true;
				ret ++;
				break ;
			}
		}
	}
	return ret;
}

int FillB () {
	int ret = 0;
	memset (B, 0, sizeof B);
	for (int j = 0; j < n; j ++) {
		for (int i = 0; i < n; i ++) {
			if (A[i][j] == '.') {
				B[i][j] = true;
				ret ++;
				break ;
			}
		}
	}
	return ret;
}

int main () {
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		cin >> A[i];
	}
	
	if ((FillA () == n) or (FillB() == n)) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (B[i][j])
					cout << i + 1 << " " << j + 1 << endl;
			}
		}
	} else
		cout << -1 << endl;
		
	return 0;
} 
