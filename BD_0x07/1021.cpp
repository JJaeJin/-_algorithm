#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	deque<int> dk;
	for (int i = 0; i < N; i++)
		dk.push_back(i + 1);

	int res = 0;
	for (int i = 0; i < M; i++) {
		int target;
		cin >> target;

		int index;
		for (int j = 0; j < dk.size(); j++) {
			if (dk[j] == target) {
				index = j;
				break;
			}
		}

		if (index < dk.size() - index) {
			res += index;
			for (int j = 0; j < index; j++) {
				dk.push_back(*dk.begin());
				dk.pop_front();
			}
		} else {
			res += dk.size() - index;
			for (int j = 0; j < dk.size() - index; j++) {
				dk.push_front(*(dk.end() - 1));
				dk.pop_back();
			}
		}
		dk.pop_front();
	}
	cout << res;

	return 0;
}