#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, H;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int box[102][102][102];
queue<tuple<int, int, int> > Q;
int res = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					Q.push(make_tuple(i, j, k));
			}
		}
	}

	while (1) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			auto [z, x, y] = Q.front();
			Q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nz = z + dz[dir];

				if (nx < 1 || nx > N || ny < 1 || ny > M || nz < 1 || nz > H)
					continue;
				if (box[nz][nx][ny] != 0)
					continue;
				box[nz][nx][ny] = 1;
				Q.push(make_tuple(nz, nx, ny));
			}
		}
		if (Q.empty())
			break;
		res++;
	}
	
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {	
				if (box[i][j][k] == 0)
					res = -1;
			}
		}
	}

	cout << res;

	return 0;
}