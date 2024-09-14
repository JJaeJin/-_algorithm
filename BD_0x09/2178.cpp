#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int		n, m;
bool	board[102][102];
int 	len[102][102];

int		dx[4] = {1, 0, -1, 0};
int		dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; j++)
			board[i][j] = temp[j - 1] - '0';
	}

	Q.push({1, 1});
	len[1][1] = 1;
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (board[nx][ny] == false)
				continue;
			if (len[nx][ny] == 0) {
				Q.push({nx, ny});
				len[nx][ny] = len[x][y] + 1;
				continue;
			}
		}
	}
	cout << len[n][m];

	return 0;
}