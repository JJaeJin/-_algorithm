#include <iostream>
#include <algorithm>

using namespace std;

int N = -1;
int arr[49];
int res[49];

void rec(int n, int start);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (N != 0) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + N);
        rec(0, 0);
        cout << '\n';
    }
    return 0;
}

void rec(int n, int start) {
    if (n == 6) {
        for (int i = 0; i < 6; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i < N; i++) {
        res[n] = arr[i];
        rec(n + 1, i + 1); 
    }
}
