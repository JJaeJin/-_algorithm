#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M, H;
int board[102][102][102];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int res = -1;
queue<tuple<int, int, int> > Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	for (int h = 1; h <= H; h++)
		for (int c = 1; c <= N; c++)
			for (int r = 1; r <= M; r++) {
				cin >> board[h][c][r];
				if (board[h][c][r] == 1)
					Q.push(make_tuple(h, c, r));
			}

	while (!Q.empty()) {
		res++;
		int ripe = Q.size();
		for (int i = 0; i < ripe; i++) {
			auto [z, x, y] = Q.front();
			Q.pop();
			for (int way = 0; way < 6; way++) {
				int nx = x + dx[way];
				int ny = y + dy[way];
				int nz = z + dz[way];

				if (nx < 1 || nx > N || ny < 1 || ny > M || nz < 1 || nz > H)
					continue;
				if (board[nz][nx][ny] != 0)
					continue;
				Q.push(make_tuple(nz, nx, ny));
				board[nz][nx][ny] = 1;
			}
		}
	}

	for (int h = 1; h <= H; h++)
		for (int c = 1; c <= N; c++)
			for (int r = 1; r <= M; r++)
				if (board[h][c][r] == 0) {
					cout << -1;
					return 0;
				}
	if (res == -1)
		res = 0;	
	cout << res;
	return 0;
}