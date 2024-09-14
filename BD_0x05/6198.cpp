#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> building;
	unsigned int res = 0;

	for (int i = 0; i < N; i++) {
		int height;

		cin >> height;
		while (building.size() != 0) {
			if (building.top() <= height) {
				building.pop();
			} else {
				// cout << "add: " << building.size() << "\n";
				res += building.size();
				break;
			}
		}

		building.push(height);
	}

	cout << res;

	return 0;
}