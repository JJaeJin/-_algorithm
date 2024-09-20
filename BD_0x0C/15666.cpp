#include <algorithm>
#include <iostream>

using namespace std;

// N개의 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.
// 고른 수열은 비내림차순이어야 한다.
int N, M;
int arr[8];
int res[8];

void rec(int n, int start);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    rec(0, 0);
    return 0;
}

void rec(int n, int start) {
    if (n == M) {
        for (int i = 0; i < M; i++) {
            cout << res[i];
            if (i + 1 == M)
                cout << '\n';
            else
                cout << ' ';
        }
        return ;
    }

    int temp = 0;
    for (int i = start; i < N; i++) {
        if (temp != arr[i]) {
            res[n] = arr[i];
            temp = arr[i];
            rec(n + 1, i);
        }
    }
}