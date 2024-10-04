#include <iostream>
#include <algorithm>

using namespace std;

// 기준
// 1. 길이
// 2. 모든 숫자 더한 값
// 3. 사전순

int N;
string st[50];

bool compare(const string &a, const string &b);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> st[i];
    }
    sort(st, st + N, compare);
    for (int i = 0; i < N; i++)
        cout << st[i] << '\n';

    return 0;
}

bool compare(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        int sumA = 0;
        int sumB = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] >= '0' && a[i] <= '9')
                sumA += a[i] - '0';
        }
        for (int i = 0; i < b.length(); i++) {
            if (b[i] >= '0' && b[i] <= '9')
                sumB += b[i] - '0';
        }
        if (sumA != sumB) {
            return sumA < sumB;
        } else {
            return a < b;
        }
    }
}
