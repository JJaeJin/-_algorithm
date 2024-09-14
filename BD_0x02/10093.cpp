#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;

	cin >> a >> b;
	if (a == b) {
		cout << 0 << "\n";
	} else {
		cout << abs(a - b) - 1 << "\n";
	}
	for (long long n = min(a, b) + 1; n <= max(a, b) - 1; n++){
		cout << n;
		if (n != max(a, b) - 1)
			cout << " ";
	}
}