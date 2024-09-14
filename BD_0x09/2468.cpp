#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int height[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int highest = 0;
int res = 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> height[i][j];
			if (height[i][j] > highest)
				highest = height[i][j];
		}
	}

	for (int water = 1; water <= highest; water++) {
		int safe_zone = 0;
		bool visit[102][102] = {false, };
		queue<pair<int, int> > Q;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (height[i][j] > water && visit[i][j] == false) {
					visit[i][j] = true;
					Q.push({i, j});
					while (!Q.empty()) {
						auto [x, y] = Q.front();
						Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = x + dx[dir];
							int ny = y + dy[dir];

							if (nx < 1 || nx > N || ny < 1 || ny > N)
								continue;
							if (height[nx][ny] <= water)
								continue;
							if (visit[nx][ny] == true)
								continue;
							visit[nx][ny] = true;
							Q.push({nx, ny});
						}
					}
					safe_zone++;
				}
			}
		}
		if (res < safe_zone)
			res = safe_zone;
	}

	cout << res;
	return 0;
}