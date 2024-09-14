#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int		n, m;
bool	board[502][502];
bool	visit[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	queue<pair<int, int> > Q;
	int pic_count = 0;
	int pic_max = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == true || board[i][j] == false)
				continue;
			visit[i][j] = true;
			Q.push({i, j});
			int pic_size = 0;
			while (!Q.empty()) {
				auto [x, y] = Q.front();
				Q.pop();
				pic_size++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx < 1 || nx > n || ny < 1 || ny > m)
						continue;
					if (visit[nx][ny] || board[nx][ny] != true)
						continue;
					visit[nx][ny] = true;
					Q.push({nx, ny});
				}
			}
			if (pic_size != 0)
				pic_count++;
			if (pic_max < pic_size)
				pic_max = pic_size;
		}
	}

	cout << pic_count << "\n" << pic_max;

	return 0;
}