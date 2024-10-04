#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long arr[100001];
long long res;
int m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    
    long long now = arr[0];
    int temp = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != now) {
            if (temp > m) {
                m = temp;
                res = now;
            }
            temp = 1;
            now = arr[i];
        } else if (i == N - 1) {
            temp++;
            if (temp > m) {
                m = temp;
                res = now;
            }
        } else {
            temp++;
        }
    }
    cout << res;

    return 0;
}