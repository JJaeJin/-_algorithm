#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// metal stick
	string ms;
	cin >> ms;

	// factory
	stack<char> ft;
	size_t res = 0;
	int now = 0;
	for (int i = 0; i < ms.size(); i++) {
		if (ms[i] == '(') {
			ft.push('(');
			now++;
		} else {
			if (ft.top() == '(') {
				now--;
				ft.push(')');
				res += now;
			} else {
				now--;
				ft.push(')');
				res++;
			}
		}
	}
	cout << res;

	return 0;
}