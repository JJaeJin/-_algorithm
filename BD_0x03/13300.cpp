#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int total_num;
	int full;
	cin >> total_num >> full;

	vector<int> kind(12);

	for (int i = 0; i < total_num; i++) {
		int male;
		int grade;
		cin >> male >> grade;
		kind[6 * male + grade - 1]++;
	}

	int res = 0;
	for (int i = 0; i < 12; i++) {
		res += kind[i] / full;
		if (kind[i] % full != 0)
			res++;
	}

	cout << res;

	return 0;
}