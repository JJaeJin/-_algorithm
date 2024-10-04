#include <algorithm>
#include <iostream>

using namespace std;

int N;
vector<long long> vi;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        reverse(temp.begin(), temp.end());
        vi.push_back(stol(temp));
    }
    sort(vi.begin(), vi.end());
    for (int i = 0; i < vi.size(); i++)
        cout << vi[i] << '\n';

    return 0;
}