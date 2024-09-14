#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;
char pic[102][102];
char pic_cb[102][102];
bool vis_n[102][102];
bool vis_cb[102][102];
int res_n = 0, res_cb = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= N; j++) {
			pic[i][j] = temp[j - 1];
			if (temp[j - 1] == 'B') {
				pic_cb[i][j] = 'B';
			} else {
				pic_cb[i][j] = 'R';
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (vis_n[i][j] == false) {
				char now = pic[i][j];
				res_n++;
				vis_n[i][j] = true;
				Q.push({i, j});
				while (!Q.empty()) {
					auto [x, y] = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 1 || nx > N || ny < 1 || ny > N)
							continue;
						if (pic[nx][ny] != now || vis_n[nx][ny] == true)
							continue;
						vis_n[nx][ny] = true;
						Q.push({nx, ny});
					}
				}
			}
			if (vis_cb[i][j] == false) {
				char now = pic_cb[i][j];
				res_cb++;
				vis_cb[i][j] = true;
				Q.push({i, j});
				while (!Q.empty()) {
					auto [x, y] = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 1 || nx > N || ny < 1 || ny > N)
							continue;
						if (pic_cb[nx][ny] != now || vis_cb[nx][ny] == true)
							continue;
						vis_cb[nx][ny] = true;
						Q.push({nx, ny});
					}
				}
			}
		}
	}

	cout << res_n << ' ' << res_cb;
	return 0;
}