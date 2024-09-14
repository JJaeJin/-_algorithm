#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		int num_back = 0;
		for (int j = 0; j < 4; j++) {
			int temp;
			cin >> temp;
			if (temp == 0)
				num_back++;
		}
		if (num_back == 0) {
			cout << "E\n";
		} else if (num_back == 1) {
			cout << "A\n";
		} else if (num_back == 2) {
			cout << "B\n";
		} else if (num_back == 3) {
			cout << "C\n";
		} else if (num_back == 4) {
			cout << "D\n";
		}
	}
	return 0;
}