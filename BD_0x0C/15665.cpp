#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int res[8];

void rec(int n);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    rec(0);
    return 0;
}

void rec(int n) {
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
    for (int i = 0; i < N; i++) {
        if (temp != arr[i]) {
            res[n] = arr[i];
            rec(n + 1);
            temp = arr[i];
        }
    }
}