#include <iostream>
#include <algorithm>

using namespace std;

// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.
int N, M;
int arr[8];

void rec(int n);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    rec(0);

    return 0;
}

void rec(int n) {
    if (n == M)
    {
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

    for (int i = 1; i <= N; i++) {
        arr[n] = i;
        rec(n + 1);
    }
}