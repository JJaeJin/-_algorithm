#include <iostream>
#include <algorithm>

using namespace std;

// N개의 자연수 중에서 M개를 고른 수열
// 고른 수열은 오름차순이어야 한다.
int N, M, temp;
vector<int> v;
int arr[8];

void rec(int n, int big);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    rec(0, 0);
    return 0;
}

void rec(int n, int big) {
    if (n == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i];
            if (i + 1 == M)
                cout << '\n';
            else
                cout << ' ';
        }
        return;
    }    

    for (int i = big; i < N; i++) {
        arr[n] = v[i];
        rec(n + 1, i + 1);
    }
}
