#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int		R, C;
char	maze[1002][1002];
deque<pair<int, int> >Q;
int		dx[4] = {1, 0, -1, 0};
int		dy[4] = {0, 1, 0, -1};
int		res = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= C; j++) {
			maze[i][j] = temp[j - 1];
			if (maze[i][j] == 'J')
				Q.push_front({i, j});
			else if (maze[i][j] == 'F')
				Q.push_back({i, j});
		}
	}

	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			auto [x, y] = Q.front();
			Q.pop_front();
			if (maze[x][y] == 'J') {
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (maze[nx][ny] == '#' || maze[nx][ny] == 'F' || maze[nx][ny] == 'J')
						continue;
					if (maze[nx][ny] == 0) {
						cout << res + 1;
						return 0;
					}
					maze[nx][ny] = 'J';
					Q.push_back({nx, ny});
				}
			} else if (maze[x][y] == 'F') {
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx < 1 || nx > R || ny < 1 || ny > C)
						continue;
					if (maze[nx][ny] == '#' || maze[nx][ny] == 'F')
						continue;
					maze[nx][ny] = 'F';
					Q.push_back({nx, ny});
				}
			}
		}
		res++;
	}

	cout << "IMPOSSIBLE";
	return 0;
}