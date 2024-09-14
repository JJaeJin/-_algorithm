#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string p;
		int n;
		deque<int> dq;

		cin >> p;
		cin >> n;

		string temp_arr;
		cin >> temp_arr;

		int pos = 0;
		for (int j = 0; j < n; j++) {
			int arg = 0;

			while (temp_arr[pos] == '[' || temp_arr[pos] == ',')
				pos++;

			while (temp_arr[pos] != ']' && temp_arr[pos] != ',') {
				arg *= 10;
				arg += temp_arr[pos] - '0';
				pos++;
			}
			dq.push_back(arg);
		}

		int rev = 1;
		int err = 0;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				rev *= -1;
			} else if (dq.size() != 0 && p[j] == 'D') {
				if (rev == 1) {
					dq.pop_front();
				} else {
					dq.pop_back();
				}
			} else {
				err = 1;
				break;
			}
		}

		if (err == 1) {
			cout << "error\n";
		} else {
			if (rev == 1) {
				cout << "[";
				for (int j = 0; j < dq.size(); j++) {
					cout << dq[j];
					if (j != dq.size() - 1)
						cout << ",";
				}
				cout << "]\n";
			} else {
				cout << "[";
				for (int j = (int)dq.size() - 1; j >= 0; j--) {
					cout << dq[j];
					if (j != 0)
						cout << ",";
				}
				cout << "]\n";	
			}
		}
	}

	return 0;
}