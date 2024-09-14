#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int res = 0;
queue<pair<int, int> > Q;
vector<int> V;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool village[27][27];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)
			village[i][j + 1] = temp[j] - '0';
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (village[i][j] == 1) {
				int size = 1;

				res++;
				Q.push({i, j});
				village[i][j] = false;
				while (!Q.empty()) {
					auto [x, y] = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx < 1 || nx > N || ny < 1 || ny > N)
							continue;
						if (village[nx][ny] == 0)
							continue;
						Q.push({nx, ny});
						village[nx][ny] = 0;
						size++;
					}
				}
				V.push_back(size);
			}
		}
	}

	cout << res << '\n';
	sort(V.begin(), V.end());
	for (int i = 0; i < res; i++) {
		cout << V[i] << '\n';
	}

	return 0;
}