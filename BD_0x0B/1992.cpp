#include <iostream>
#include <algorithm>

using namespace std;

void cut(int x, int y, int n);
bool all_same(int x, int y, int n);

int N;
int board[64][64];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)
			board[i][j] = temp[j] - '0';
	}

	cut(0, 0, N);

	return 0;
}

void cut(int x, int y, int n) {
	if (n == 1 || all_same(x, y, n)) {
		cout << board[x][y];
		return;
	}

	cout << "(";
	int next = n / 2;
	cut(x, y, next);
	cut(x, y + next, next);
	cut(x + next, y, next);
	cut(x + next, y + next, next);
	cout << ")";
}

bool all_same(int x, int y, int n) {
	int stand = board[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[i][j] != stand)
				return false;
	return true;
}