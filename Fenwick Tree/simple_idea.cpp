#include<bits/stdc++.h>
using namespace std;

int bit[220797];
int n = 20;

void update(int x, int v) {
	for (; x <= n; x += x & -x) bit[x] += v;
}
int get(int x) {
	int res = 0;
	for (; x >= 1; x &= x - 1) res += bit[x];
	return res;
}

int main(void) {
	for (int i = 1; i <= 24; i++) {
		int a = i - (i & -i);
		int b = i & (i - 1);
		printf("i = %d, a = %d, b = %d\n", i, a, b);
	}
	
	return 0;

}

//https://ideone.com/KSJ6v8

// i = 1, a = 0, b = 0
// i = 2, a = 0, b = 0
// i = 3, a = 2, b = 2
// i = 4, a = 0, b = 0
// i = 5, a = 4, b = 4
// i = 6, a = 4, b = 4
// i = 7, a = 6, b = 6
// i = 8, a = 0, b = 0
// i = 9, a = 8, b = 8
// i = 10, a = 8, b = 8
// i = 11, a = 10, b = 10
// i = 12, a = 8, b = 8
// i = 13, a = 12, b = 12
// i = 14, a = 12, b = 12
// i = 15, a = 14, b = 14
// i = 16, a = 0, b = 0
// i = 17, a = 16, b = 16
// i = 18, a = 16, b = 16
// i = 19, a = 18, b = 18
// i = 20, a = 16, b = 16
// i = 21, a = 20, b = 20
// i = 22, a = 20, b = 20
// i = 23, a = 22, b = 22
// i = 24, a = 16, b = 16