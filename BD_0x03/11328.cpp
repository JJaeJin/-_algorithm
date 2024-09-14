#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
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
	
		int possible = 1;
		for (int j = 0; j < 26; j++) {
			if (alphabet[j] != 0)
				possible = 0;
		}
		if (possible) {
			cout << "Possible\n";
		} else {
			cout << "Impossible\n";
		}
	}

	return 0;
}