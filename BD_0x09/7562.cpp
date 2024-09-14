#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, l;
int start_x, start_y, goal_x, goal_y;
int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		bool board[302][302] = {0, };
		queue<pair<int, int> >Q;
		int res = 0;
		int fin = 0;
		
		cin >> l;
		cin >> start_x >> start_y >> goal_x >> goal_y;
		start_x++;
		start_y++;
		goal_x++;
		goal_y++;
		board[start_x][start_y] = 1;
		Q.push({start_x, start_y});
		while (fin == 0) {
			int size = Q.size();
			for (int j = 0; j < size; j++) {
				auto [x, y] = Q.front();
				Q.pop();
				if (x == goal_x && y == goal_y) {
					cout << res << '\n';
					fin = 1;
					break;
				}
				for (int dir = 0; dir < 8; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx < 1 || nx > l || ny < 1 || ny > l)
						continue;
					if (board[nx][ny] == 1)
						continue;
					Q.push({nx, ny});
					board[nx][ny] = 1;
				}
			}
			res++;
		}
	}

	return 0;
}