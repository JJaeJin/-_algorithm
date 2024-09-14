#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, n;
int tomato[1002][1002] = {-1, };
queue<pair<int, int> >Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int res = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				Q.push({i, j});
		}
	}

	while (1) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			auto [x, y] = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 1 || nx > n || ny < 1 || ny > m)
					continue;
				if (tomato[nx][ny] == -1 || tomato[nx][ny] == 1)
					continue;
				tomato[nx][ny] = 1;
				Q.push({nx, ny});
			}
		}
		if (Q.empty())
			break;
		res++;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (tomato[i][j] == 0)
				res = -1;

	cout << res;

	return 0;
}