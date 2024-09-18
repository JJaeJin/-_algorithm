#include <iostream>
#include <algorithm>

using namespace std;

int N, S, res;
int arr[20];

void rec(int n, int sum);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    rec(0, 0);
    if (S == 0)
        res--;
    cout << res;

    return 0;
}

void rec(int n, int sum)
{
    if (n == N)
    {
        if (sum == S)
            res++;
        return;
    }

    rec(n + 1, sum);
    rec(n + 1, sum + arr[n]);
}