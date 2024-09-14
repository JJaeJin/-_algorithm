#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(1000001);

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v[temp]++;
	}
	
	int x;
	cin >> x;

	int res = 0;
	for (int i = 1; i <= x / 2; i++) {
		if (2 * i != x && v[i] != 0 && x - i < 1000001 && v[x - i] != 0) {
			res++;
		}
	}

	cout << res;
	return 0;
}