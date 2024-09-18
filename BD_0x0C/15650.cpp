#include <iostream>
#include <algorithm>

using namespace std;

// 1부터 N까지 자연수 중 중복 없이 M개를 고른 수열
// 고른 수열은 오름차순이어야 한다.
int N, M;
bool isused[9];
int arr[8];

void rec(int n, int big);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    rec(0, 0);

    return 0;
}

void rec(int n, int big) {
    if (n == M) {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i];
            if (i + 1 == M)
                cout << '\n';
            else
                cout << ' ';
        }
        return;
    }

    for (int i = big + 1; i <= N; i++) {
        if (!isused[i]) {
            isused[i] = true;
            arr[n] = i;
            rec(n + 1, i);
            isused[i] = false;
        }
    }
}
