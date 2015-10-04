#include<stdio.h>
#include<math.h>

int abs (int a) {
	if (a < 0)
		return -a;
	return a;
}

int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Leap (int y) {
	if (y % 4 != 0)
		return 0;
	if ((y % 4 == 0) and (y % 100 != 0))
		return 1;
	if ((y % 100 == 0) and (y % 400 == 0))
		return 1;
	return 0;
}

int ToDate (int y, int m, int d) {
	int ret = 0;
	
	for (int i = 1900; i <= y; i ++) {
		for (int j = 1; j <= 12; j ++) {
			if (i != y or j < m) {
				ret += M[j] + (j == 2 and Leap(i));
			} else if (i == y and j == m) {
				ret += d;
				break ;
			}
		}
	}
	
	return ret;
}

int y, m, d, date1, date2;

int main() {
	scanf ("%d:%d:%d", &y, &m, &d);
	date1 = ToDate(y, m, d);
	scanf ("%d:%d:%d", &y, &m, &d);
	date2 = ToDate(y, m, d);
	
//	printf ("%d %d\n", date1, date2);
	printf ("%d\n", abs (date2 - date1));
	
	return 0;
}
