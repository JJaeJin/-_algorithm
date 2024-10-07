#include <iostream>
#include <algorithm>

using namespace std;

string S;
vector<string> tail;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    int len = S.size();
    for (int i = 0; i < len; i++) {
        string temp = S.substr(i, len - i);
        tail.push_back(temp);
    }
    sort(tail.begin(), tail.end());
    for (int i = 0; i < tail.size(); i++)
        cout << tail[i] << '\n';

    return 0;
}