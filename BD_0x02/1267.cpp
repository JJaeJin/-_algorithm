#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num_call;
	cin >> num_call;

	int total_y = 0, total_m = 0;
	for (int i = 0; i < num_call; i++) {
		int temp;
		cin >> temp;
		total_y += 10 * (1 + temp / 30);
		total_m += 15 * (1 + temp / 60);
	}

	if (total_m > total_y) {
		cout << "Y " << total_y;
	} else if (total_m < total_y) {
		cout << "M " << total_m;
	} else {
		cout << "Y M " << total_m;
	}
}