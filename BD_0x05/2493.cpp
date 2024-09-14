#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> tower_stack;
	stack<int> hide;
	for (int i = 0; i < N; i++) {
		int tower;
		int temp_hide = 0;
		int res = i;

		cin >> tower;
		while (tower_stack.size() != 0) {
			if (tower_stack.top() < tower) {
				tower_stack.pop();
				temp_hide += hide.top() + 1;
				res -= hide.top() + 1;
				hide.pop();
			} else {
				break;
			}
		}

		tower_stack.push(tower);
		hide.push(temp_hide);

		cout << res;
		if (i != N - 1)
			cout << " ";
	}

	return 0;
}