#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        cout << v[i] << '\n';

    return 0;
}