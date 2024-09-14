#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int odd_sum = 0, odd_min = 101;

	for (int i = 0; i < 7; i++) {
		int temp;
		cin >> temp;
		if (temp % 2 == 1) {
			odd_sum += temp;
			if (odd_min > temp)
				odd_min = temp;
		}
	}
	if (odd_sum == 0) {
		cout << -1;
	} else {
		cout << odd_sum << "\n";
		cout << odd_min;
	}
}