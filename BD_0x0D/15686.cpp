#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int vil[50][50];
int res = 2147483647;
int total_chicken;
int now_chicken;
vector<pair<int, int> > v;

void solve(int n);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int c = 0; c < N; c++){
        for (int r = 0; r < N; r++) {
            cin >> vil[c][r];
            if (vil[c][r] == 2) {
                v.push_back(make_pair(c, r));
                total_chicken++;
            }
        }
    }
    solve(0);
    cout << res;

    return 0;
}

int get_distance(int c1, int r1, int c2, int r2) {
    return abs(c1 - c2) + abs(r1 - r2);
}

int get_chicken_dis(int c, int r) {
    int res = 2 * (N - 1);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (vil[i][j] == 2) {
                int d = get_distance(c, r, i, j);
                if (d < res)
                    res = d;
            }
    return res;
}

void get_res() {
    int temp = 0;

    for (int c = 0; c < N; c++) {
        for (int r = 0; r < N; r++) {
            if (vil[c][r] == 1) {
                temp += get_chicken_dis(c, r);
            }
        }
    }
    if (res > temp)
        res = temp;
}

void solve(int n) {
    if (n == total_chicken) {
        if (now_chicken == M) {
            // cout << "@@@@@@@@@@@@@@@@@@@@@@@@\n";
            // for (int i = 0; i < N; i++) {
            //     for (int j = 0; j < N; j++) {
            //         cout << vil[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << "@@@@@@@@@@@@@@@@@@@@@@@@\n";

            get_res();
        }
        return;
    }
    auto [x, y] = v[n];

    vil[x][y] = 0;
    solve(n + 1);
    vil[x][y] = 2;
    now_chicken++;
    solve(n + 1);
    now_chicken--;
}