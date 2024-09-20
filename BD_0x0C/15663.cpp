#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// N개의 자연수 중에서 M개를 고른 수열
int N, M, temp;
int arr[8];
int res[8];
bool isused[8];
set<vector<int> >s;

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
        return;
    }

    int temp = 0;
    for (int i = 0; i < N; i++) {
        if (!isused[i] && temp != arr[i]) {
            isused[i] = true;
            res[n] = arr[i];
            temp = arr[i];
            rec(n + 1);
            isused[i] = false;
        }
    }
}