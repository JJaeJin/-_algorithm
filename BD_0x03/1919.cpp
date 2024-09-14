#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string before;
	string after;
	vector<int> alphabet(26);

	cin >> before >> after;
	for (int j = 0; j < before.size(); j++) {
		alphabet[before[j] - 'a']++;
	}
	for (int j = 0; j < after.size(); j++) {
		alphabet[after[j] - 'a']--;
	}

	int res = 0;

	for (int j = 0; j < 26; j++) {
		res += abs(alphabet[j]);
	}
	cout << res;

	return 0;
}