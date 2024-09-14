#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	list<int> nums;
	for (int i = 0; i < N; i++)
		nums.push_back(i + 1);

	cout << "<";
	list<int>::iterator temp_it;
	temp_it = nums.begin();
	while (nums.size() != 0) {
		for (int i = 0; i < K - 1; i++) {
			if (temp_it == --nums.end()) {
				temp_it = nums.begin();
			} else {
				temp_it++;
			}
		}
		cout << *temp_it;
		if (nums.size() != 1)
			cout << ", ";
		temp_it = nums.erase(temp_it);
		if (temp_it == nums.end())
			temp_it = nums.begin();
	}
	cout << ">";

	return 0;
}