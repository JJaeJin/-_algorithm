#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, M, N, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> >Q;
int res;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		bool farm[52][52] = {0, };
		bool visit[52][52] = {0, };
		res = 0;
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			farm[x + 1][y + 1] = true;
		}
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= N; k++) {
				if (farm[j][k] == true && visit[j][k] == false) {
					res++;
					Q.push({j, k});
					visit[j][k] = true;
					while (!Q.empty()) {
						auto [x, y] = Q.front();
						Q.pop();
						for (int l = 0; l < 4; l++) {
							int nx = x + dx[l];
							int ny = y + dy[l];
							
							if (nx < 1 || nx > M || ny < 1 || ny > N)
								continue;
							if (farm[nx][ny] == false || visit[nx][ny] == true)
								continue;
							visit[nx][ny] = true;
							Q.push({nx, ny});
						}
					}
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}