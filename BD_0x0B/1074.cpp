#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, r, c;
int find_z(int n, int x, int y);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;
	cout << find_z(N, c, r);

	return 0;
}

int find_z(int n, int x, int y) {
	if (n == 0) 
		return 0;

	int st = pow(2, n - 1);
	int block = st * st;

	if (x < st && y < st) {
		return find_z(n - 1, x, y);
	} else if (x >= st && y < st) {
		return block + find_z(n - 1, x - st, y);
	} else if (x < st && y >= st) {
		return block * 2 + find_z(n - 1, x, y - st);
	} else if (x >= st && y >= st) {
		return block * 3 + find_z(n - 1, x - st, y - st);
	}

	return 0;
}
