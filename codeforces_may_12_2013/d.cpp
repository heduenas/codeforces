#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int n, m, x, y, a, b;
int w, h;

int gdc (int a, int b) {
	if (b == 0)
		return a;
	int c = a % b;
	return gdc (b, c);
}

int main() {
//	scanf ("%I64d%I64d%I64d%I64d%I64d%I64d", &n, &m, &x, &y, &a, &b);
	cin >> n>> m>> x>> y>> a>> b;
	int g = gdc (a, b);
	a /= g;
	b /= g;
	
	int Min = n / a;
	if (m / b < Min)
		Min = m / b;
	
	w = a * Min;
	h = b * Min;
	
	int x1, y1;
	x1 = x - (w+1) / 2;
	y1 = y - (h+1) / 2;
	
	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	if (x1 + w > n)
		x1 = n- w;
	if (y1 + h > m)
		y1 = m- h;
	
	
	cout << x1 << " " << y1<< " " << x1 + w<< " " << h + y1 << endl;
//	printf ("%d %d %d %d\n", x1, y1, x1 + w, h + y1);
	
//	printf ("%I64d %I64d\n", w, h);
		
	return 0;
}
