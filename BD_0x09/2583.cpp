#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int M, N, K;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[102][102];
int start_x, start_y, end_x, end_y;
int w, h;
queue<pair<int, int> > Q;
vector<int> V;
int res;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> K;
	while (K--) {
		cin >> start_y >> start_x >> end_y >> end_x;
		w = end_y - start_y;
		h = end_x - start_x;
		for (int i = 1 + start_x; i < 1 + start_x + h; i++)
			for (int j = 1 + start_y; j < 1 + start_y + w; j++)
				board[i][j]++;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == 0) {
				int size = 0;
				res++;
				Q.push({i, j});
				board[i][j]++;
				while (!Q.empty()) {
					auto [x, y] = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx < 1 || nx > M || ny < 1 || ny > N)
							continue;
						if (board[nx][ny] > 0)
							continue;
						Q.push({nx, ny});
						board[nx][ny]++;
					}
					size++;
				}
				V.push_back(size);
			}
		}
	}

	cout << res << '\n';
	sort(V.begin(), V.end());
	for (int i = 0; i < res; i++) {
		cout << V[i];
		if (i != res - 1)
			cout << ' ';
	}

	return 0;
}