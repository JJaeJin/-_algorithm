#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		list<char> res;
		list<char>::iterator cs = res.begin();
		string temp;

		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == '<') {
				if (cs != res.begin())
					cs--;
			} else if (temp[j] == '>') {
				if (cs != res.end())
					cs++;
			} else if (temp[j] == '-') {
				if (cs != res.begin())
					cs = res.erase(--cs);
			} else {
				res.insert(cs, temp[j]);
			}
		}
		for (list<char>::iterator it = res.begin(); it != res.end(); it++)
			cout << *it;
		cout << "\n";
	}

	return 0;
}