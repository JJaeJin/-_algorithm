#include <iostream>
#include <algorithm>

using namespace std;

bool all_same(int n, int x, int y);
void cut(int n, int x, int y);

int N;
int m, z, p;
int board[2187][2187];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cut(N, 0, 0);
	cout << m << '\n';
	cout << z << '\n';
	cout << p << '\n';
	return 0;
}

void cut(int n, int x, int y) {
	if (n == 1 || all_same(n, x, y)) {
		if (board[x][y] == -1) {
			m++;
		} else if (board[x][y] == 0) {
			z++;
		} else {
			p++;
		}
		return;
	}
	int next = n / 3;
	cut(next, x, y);
	cut(next, x, y + next);
	cut(next, x, y + next * 2);
	cut(next, x + next, y);
	cut(next, x + next * 2, y);
	cut(next, x + next, y + next);
	cut(next, x + next, y + next * 2);
	cut(next, x + next * 2, y + next);
	cut(next, x + next * 2, y + next * 2);
}

bool all_same(int n, int x, int y) {
	int stand = board[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[i][j] != stand)
				return false;
	return true;
}