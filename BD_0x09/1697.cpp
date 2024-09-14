#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int		N, K;
bool	visit[100001] = {false, };
queue<int> Q;
int res = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	visit[N] = true;
	Q.push(N);
	while (1) {
		int turn = Q.size();
		for (int i = 0; i < turn; i++) {
			int now = Q.front();
			if (now == K){
				cout << res;
				return 0;
			}
			Q.pop();
			if (now * 2 < 100001 && visit[now * 2] == false) {
				Q.push(now * 2);
				visit[now * 2] = true;
			}
			if (now - 1 >= 0 && visit[now - 1] == false) {
				Q.push(now - 1);
				visit[now - 1] = true;
			}
			if (now + 1 < 100001 && visit[now + 1] == false) {
				Q.push(now + 1);
				visit[now + 1] = true;
			}
		}
		res++;
	}
	return 0;
}