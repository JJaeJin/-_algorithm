#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int wrong_paren(void);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<int> res;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			res.push(-1);
		} else if (s[i] == '[') {
			res.push(-2);
		} else if (s[i] == ')') {
			if (res.size() == 0)
				return wrong_paren();
			if (res.top() == -1) {
				res.pop();
				res.push(2);
			} else {
				int temp = 0;
				while (res.size() != 0 && res.top() != -1) {
					if (res.top() == -2)
						return wrong_paren();
					temp += res.top();
					res.pop();
				}
				if (res.size() == 0)
					return wrong_paren();
				res.pop();
				res.push(temp * 2);
			}
		} else if (s[i] == ']') {
			if (res.size() == 0)
				return wrong_paren();
			if (res.top() == -2) {
				res.pop();
				res.push(3);
			} else {
				int temp = 0;
				while (res.size() != 0 && res.top() != -2) {
					if (res.top() == -1)
						return wrong_paren();
					temp += res.top();
					res.pop();
				}
				if (res.size() == 0)
					return wrong_paren();
				res.pop();
				res.push(temp * 3);
			}
		}
	}
	int res_i = 0;
	while (res.size() != 0) {
		if (res.top() < 0)
			return wrong_paren();
		res_i += res.top();
		res.pop();
	}
	cout << res_i;
	return 0;
}

int wrong_paren(void) {
	cout << 0;
	return 0;
}