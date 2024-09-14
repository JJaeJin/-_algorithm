#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool isused[14][14];
int res;

void func(int n);
bool check_board(int r, int c);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    func(0);
    cout << res;

    return 0;
}

void func(int n)
{
    if (n == N)
    {
        res++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!check_board(i, n))
            continue;
        isused[i][n] = true;
        func(n + 1);
        isused[i][n] = false;
    }
}

bool check_board(int r, int c)
{
    for (int i = 0; i < N; i++)
        if (isused[r][i] || isused[i][c])
            return false;
    for (int tr = r, tc = c; tr < N && tc >= 0; tr++, tc--)
        if (isused[tr][tc])
            return false;
    for (int tr = r, tc = c; tr >= 0 && tc >= 0; tr--, tc--)
        if (isused[tr][tc])
            return false;

    return true;
}