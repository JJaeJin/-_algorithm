#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, w, h;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		char room[1002][1002] = {0, };
		deque<pair<int, int> > D;
		int res = 0;
		int fin = 0;

		cin >> w >> h;
		for (int i = 1; i <= h; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < w; j++) {
				room[i][j + 1] = temp[j];
				if (room[i][j + 1] == '@')
					D.push_front({i, j + 1});
				else if (room[i][j + 1] == '*')
					D.push_back({i, j + 1});
			}
		}

		while (1) {
			int size = D.size();
			while (size--) {
				auto [x, y] = D.front();
				D.pop_front();
				if (room[x][y] == '@') {
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (room[nx][ny] == '#' || room[nx][ny] == '*' || room[nx][ny] == '@')
							continue;
						if (room[nx][ny] == 0) {
							cout << res + 1 << '\n';
							fin = 1;
							break;
						}
						D.push_back({nx, ny});
						room[nx][ny] = '@';
					}
				} else if (room[x][y] == '*') {
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx < 1 || nx > h || ny < 1 || ny > w)
							continue;
						if (room[nx][ny] == '#' || room[nx][ny] == '*')
							continue;
						D.push_back({nx, ny});
						room[nx][ny] = '*';
					}
				}
				if (fin == 1)
					break;
			}
			if (fin == 1)
				break;
			res++;
			if (D.empty()) {
				cout << "IMPOSSIBLE\n";
				break;
			}
		}
	}

	return 0;
}