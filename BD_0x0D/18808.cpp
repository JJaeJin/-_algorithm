#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
bool sticker[100][10][10];
bool laptop[40][40];
int res;

bool can_attach(int n, int x, int y);
void attach(int n, int x, int y);
void spin_s(int n);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int w, h;
        cin >> h >> w;
        for (int j = 0; j < h; j++)
            for (int k = 0; k < w; k++)
                cin >> sticker[i][j][k];
    }
    int n = 0;
    while (n != K) {
        bool a_flag = false;
        // 돌리는 경우의수
        for (int spin = 0; !a_flag && spin < 4; spin++) {
            // 스티커 붙이는 경우의수
            for (int i = -9; !a_flag && i < N; i++) {
                for (int j = -9; !a_flag && j < M; j++) {
                    if (can_attach(n, i, j)) {
                        attach(n, i, j);
                        a_flag = true;
                    }
                }
            }
            if (!a_flag)
                spin_s(n);
        }
        n++;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (laptop[i][j])
                res++;
    cout << res;
    return 0;
}

bool can_attach(int n, int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (sticker[n][i][j] && 
                (x + i >= N || x + i < 0 
                || y + j >= M || y + j < 0 
                || laptop[x + i][y + j])) {
                return false;
            }
        }
    }
    return true;
}

void attach(int n, int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (sticker[n][i][j]) {
                laptop[x + i][y + j] = true;
            }
        }
    }
}

void spin_s(int n) {
    bool temp[10][10] = {0, };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (sticker[n][i][j]) {
                temp[j][9 - i] = true;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sticker[n][i][j] = temp[i][j];
        }
    }
}