#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> A;
	stack<int> bigs;
	stack<int> res;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push(temp);
	}

	for (int i = 0; i < N; i++) {
		int temp;
		temp = A.top();
		A.pop();

		if (i == 0) {
			res.push(-1);
			bigs.push(temp);
		} else {
			if (temp < bigs.top()) {
				res.push(bigs.top());
			} else {
				while (bigs.size() != 0) {
					if (temp < bigs.top()) {
						break;
					} else {
						bigs.pop();
					}
				}
				if (bigs.size() == 0) {
					res.push(-1);
				} else {
					res.push(bigs.top());
				}
			}
			bigs.push(temp);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << res.top();
		if (i != N - 1) {
			cout << " ";
			res.pop();
		}
	}

	return 0;
}