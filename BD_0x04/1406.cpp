#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> str;
	string temp_str;
	cin >> temp_str;

	for (int i = 0; i < temp_str.size(); i++) {
		str.push_back(temp_str[i]);
	}

	int num;
	list<char>::iterator now = str.end();
	cin >> num;

	for (int i = 0; i < num; i++) {
		string command;
		cin >> command;

		if (command == "L") {
			if (now != str.begin())
				now--;
		}else if (command == "D") {
			if (now != str.end())
				now++;
		}else if (command == "B") {
			if (now != str.begin()) {
				now = str.erase(--now);
			}
		}else if (command == "P") {
			char temp_char;
			cin >> temp_char;

			now = str.insert(now, temp_char);
			now++;
		}
	}

	for (list<char>::iterator it = str.begin(); it != str.end(); it++) {
		cout << *it;
	}

	return 0;
}