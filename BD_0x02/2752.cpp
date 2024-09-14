#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int big, small;
	big = max({a, b, c});
	small = min({a, b, c});
	cout << small << " " << a + b + c - big - small << " " << big;
}