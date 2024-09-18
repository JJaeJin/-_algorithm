#include <iostream>
#include <algorithm>

using namespace std;

// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.고른 수열은 비내림차순이어야 한다.
// 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK - 1 ≤ AK를 만족하면, 비내림차순이라고 한다.
int N, M;
int arr[8];
void rec(int n, int big);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    rec(0, 1);

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

    for (int i = big; i <= N; i++) {
        arr[n] = i;
        rec(n + 1, i);
    }
}