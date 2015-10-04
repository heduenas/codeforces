#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

char str[1000010];
char heavy[] = "heavy";
char metal[] = "metal";
long long len;
bool L[1000010], R[1000010];

int main() {
	scanf ("%s", str);
	len = strlen (str);
	
	for (int i = 0; i < len; i ++) {
			bool valid = true;
			for (int j = 0; j < 5; j ++) {
					if (str[i + j] != heavy[j]) {
						valid = false;
						break;
					}
			}
			L[i] = valid;
			
			valid = true;
			for (int j = 0; j < 5; j ++) {
					if (str[i + j] != metal[j]) {
						valid = false;
						break;
					}
			}
			R[i] = valid;
	}
	
	long long count = 0, ans = 0;
	for (int i = 0; i < len; i ++) {
		if (L[i])
			count ++;
		else if (R[i])
			ans += count;
	}
	
	cout << ans << endl;
	
	return 0;
}
