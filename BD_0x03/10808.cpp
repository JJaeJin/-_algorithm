#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(26);

	string S;
	cin >> S;
	
	for (int i = 0; i < S.size(); i++)
		v[S[i] - 'a']++;

	for (int i = 0; i < 26; i++) {
		cout << v[i];
		if (i != 25)
			cout << " ";
	}
}