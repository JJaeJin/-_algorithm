#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int res[8];

void rec(int n);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	rec(M);
	return 0;
}

void rec(int n) {
	if (n == 0) {
		for (int i = 0; i < M; i++) {
			cout << res[i];
			if (i == M - 1) {
				cout << "\n";
			} else {
				cout << " ";
			}
		}
		return ;
	}

	for (int i = 1; i <= N; i++) {
		bool same = false;
		for (int j = 0; j < M - n; j++) {
			if (res[j] == i) {
				same = true;
				break;
			}
		}
		if (same == false) {
			res[M - n] = i;
			rec(n - 1);
		}
	}
}