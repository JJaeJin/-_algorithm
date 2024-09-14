#include <iostream>
#include <algorithm>

using namespace std;

void cut(int x, int y, int n);
bool all_same(int x, int y, int n);

int N;
int board[128][128];
int w, b;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cut(0, 0, N);
	cout << w << '\n';
	cout << b << '\n';

	return 0;
}

void cut(int x, int y, int n) {
	if (n == 1 || all_same(x, y, n)) {
		if (board[x][y] == 1) {
			b++;
		} else {
			w++;
		}
		return;
	}

	int next = n / 2;
	cut(x, y, next);
	cut(x + next, y, next);
	cut(x, y + next, next);
	cut(x + next, y + next, next);
}

bool all_same(int x, int y, int n) {
	int stand = board[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[i][j] != stand)
				return false;
	return true;
}