#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int n, m;
bool board[502][502];
bool isvisit[502][502];
int num, dmax;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int> > dq;

int main(void) {
	ios::sync_with_stdio();
	cin.tie();

	cin >> n >> m;
	for (int c = 1; c <= n; c++)
		for (int r = 1; r <= m; r++)
			cin >> board[c][r];

	for (int c = 1; c <= n; c++) {
		for (int r = 1; r <= m; r++) {
			if (board[c][r] && !isvisit[c][r]) {
				num++;
				int temp = 0;
				dq.push_back(make_pair(c, r));
				isvisit[c][r] = true;
				while (!dq.empty()) {
					auto [x, y] = dq.front();
					dq.pop_front();
					temp++;
					for (int way = 0; way < 4; way++) {
						int nx = x + dx[way];
						int ny = y + dy[way];

						if (nx < 1 || nx > n || ny < 1 || ny > m)
							continue;
						if (isvisit[nx][ny] || !board[nx][ny])
							continue;
						
						isvisit[nx][ny] = true;
						dq.push_back(make_pair(nx, ny));
					}
				}
				if (temp > dmax)
					dmax = temp;
			}
		}
	}

	cout << num << '\n' << dmax;

	return 0;
}