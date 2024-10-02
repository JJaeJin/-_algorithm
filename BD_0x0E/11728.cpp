#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v1;
vector<int> v2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        v2.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i1 = 0, i2 = 0; i1 + i2 < N + M; ) {
        if (i1 < N && i2 < M) {
            if (v1[i1] < v2[i2])
                cout << v1[i1++] << ' ';
            else
                cout << v2[i2++] << ' ';
        } else if (i1 < N) {
            cout << v1[i1++] << ' ';
        } else {
            cout << v2[i2++] << ' ';
        }
    }

    return 0;
}