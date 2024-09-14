#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(10);
	int res = 0;
	
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
		v[s[i] - '0']++;

	v[6] = (v[6] + v[9]) / 2 + (v[6] + v[9]) % 2;

	for (int i = 0; i < 9; i++)
		if (v[i] > res)
			res = v[i];

	cout << res;
	return 0;
}