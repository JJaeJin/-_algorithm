#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int card[20];
	for (int i = 0; i < 20; i++)
		card[i] = i + 1;

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		for (;a < b; a++, b--) {
			int temp = card[a - 1];
			card[a - 1] = card[b - 1];
			card[b - 1] = temp;
		}
	}
	
	for (int i = 0; i < 20; i++) {
		cout << card[i];
		if (i != 19)
			cout << " ";
	}
}