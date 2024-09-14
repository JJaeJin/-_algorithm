#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int res = 0;
	for (int i = 0; i < N; i++) {
		stack<char> st;
		string word;
		cin >> word;

		for (int j = 0; j < word.size(); j++) {
			if (st.size() == 0) {
				st.push(word[j]);
			} else if (st.top() == word[j]) {
				st.pop();
			} else {
				st.push(word[j]);
			}
		}
		if (st.size() == 0)
			res++;
	}

	cout << res;

	return 0;
}