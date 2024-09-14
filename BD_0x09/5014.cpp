#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool building[1000002];
queue<int> Q;
int res;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;
	if (S == G) {
		cout << 0;
		return 0;
	}
	Q.push(S);
	building[S] = true;
	while (!Q.empty()) {
		int size = Q.size();
		while (size--) {
			int now = Q.front();
			Q.pop();
			if (now + U > 0 && now + U <= F && building[now + U] == false) {
				if (now + U == G) {
					cout << res + 1;
					return 0;
				}
				building[now + U] = true;
				Q.push(now + U);
			}
			if (now - D > 0 && now - D <= F && building[now - D] == false) {
				if (now - D == G) {
					cout << res + 1;
					return 0;
				}
				building[now - D] = true;
				Q.push(now - D);
			}
		}
		res++;
	}

	cout << "use the stairs";
	return 0;
}