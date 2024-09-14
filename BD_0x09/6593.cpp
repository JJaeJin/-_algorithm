#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int L, R, C;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> R >> C;
	while (L != 0 && R != 0 && C != 0) {
		char maze[32][32][32];
		queue<tuple<int, int, int> > Q;
		bool fin = false;
		int res = 0;

		for (int z = 1; z <= L; z++) {
			for (int x = 1; x <= R; x++) {
				string temp;
				cin >> temp;
				for (int y = 1; y <= C; y++) {
					maze[z][x][y] = temp[y - 1];
					if (maze[z][x][y] == 'S')
						Q.push(make_tuple(z, x, y));
				}
			}
		}

		while (!fin) {
			int size = Q.size();
			while (size--) {
				auto [z, x, y] = Q.front();
				Q.pop();
				for (int dir = 0; dir < 6; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					int nz = z + dz[dir];

					if (nx < 1 || nx > R || ny < 1 || ny > C || nz < 1 || nz > L)
						continue;
					if (maze[nz][nx][ny] == 'E') {
						cout << "Escaped in " << res + 1 << " minute(s).\n";
						fin = true;
						break;
					}
					if (maze[nz][nx][ny] != '.')
						continue;
					maze[nz][nx][ny] = 'S';
					Q.push(make_tuple(nz, nx, ny));
				}
				if (fin)
					break;
			}
			if (Q.empty())
				break;
			res++;
		}

		if (!fin)
			cout << "Trapped!\n";

		cin >> L >> R >> C;
	}

	return 0;
}