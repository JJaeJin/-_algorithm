#include <iostream>
#include <algorithm>

using namespace std;

int N, M, res, cctv;
int office[8][8];
int sight[8][8];
vector<pair<int, int> > v;

void rec(int n);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    res = N * M;
    for (int c = 0; c < N; c++) {
        for (int r = 0; r < M; r++) {
            int temp;
            cin >> temp;
            if (temp != 0 && temp != 6) {
                v.push_back(make_pair(c, r));
                cctv++;
            }
            office[c][r] = temp;
        }
    }

    rec(0);
    cout << res;
    
    return 0;
}

void rec(int n) {
    if (n == cctv) {
        int unvisible = 0;
        for (int c = 0; c < N; c++)
            for (int r = 0; r < M; r++)
                if (sight[c][r] == 0 && office[c][r] != 6)
                    unvisible++;
        if (res > unvisible) {
            res = unvisible;
        }
        return;
    }

    vector<pair<int, int> > change;
    auto[x, y] = v[n];
    // 5번 CCTV일 때
    if (office[x][y] == 5) {
        if (sight[x][y] != '#') {
            change.push_back(make_pair(x, y));
            sight[x][y] = '#';
        }
        for (int i = y; i < M; i++) {
            if (office[x][i] == 6)
                break;
            if (sight[x][i] != '#') {
                change.push_back(make_pair(x, i));
                sight[x][i] = '#';
            }
        }
        for (int i = y; i >= 0; i--) {
            if (office[x][i] == 6)
                break;
            if (sight[x][i] != '#') {
                change.push_back(make_pair(x, i));
                sight[x][i] = '#';
            }
        }
        for (int i = x; i < N; i++) {
            if (office[i][y] == 6)
                break;
            if (sight[i][y] != '#') {
                change.push_back(make_pair(i, y));
                sight[i][y] = '#';
            }
        }
        for (int i = x; i >= 0; i--) {
            if (office[i][y] == 6)
                break;
            if (sight[i][y] != '#') {
                change.push_back(make_pair(i, y));
                sight[i][y] = '#';
            }
        }
        rec(n + 1);
        for (int i = 0; i < change.size(); i++)
            sight[change[i].first][change[i].second] = 0;
        change.clear();
    }
    // 4번 CCTV일 때
    if (office[x][y] == 4) {
        for (int way = 0; way < 4; way++) {
            if (sight[x][y] != '#') {
                change.push_back(make_pair(x, y));
                sight[x][y] = '#';
            }
            if (way != 0)
                for (int i = y; i < M; i++) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way != 1)
                for (int i = y; i >= 0; i--) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way != 2)
                for (int i = x; i < N; i++) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }
            if (way != 3)
                for (int i = x; i >= 0; i--) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }  
            rec(n + 1);
            for (int i = 0; i < change.size(); i++)
                sight[change[i].first][change[i].second] = 0;
            change.clear();
        }
    }
    // 3번 CCTV
    if (office[x][y] == 3) {
        for (int way = 0; way < 4; way++) {
            if (sight[x][y] != '#') {
                change.push_back(make_pair(x, y));
                sight[x][y] = '#';
            }
            if (way == 0 || way == 1)
                for (int i = y; i < M; i++) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way == 2 || way == 3)
                for (int i = y; i >= 0; i--) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way == 0 || way == 2)
                for (int i = x; i < N; i++) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }
            if (way == 1 || way == 3)
                for (int i = x; i >= 0; i--) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }  
            rec(n + 1);
            for (int i = 0; i < change.size(); i++)
                sight[change[i].first][change[i].second] = 0;
            change.clear();
        }
    }
    // 2번 CCTV
    if (office[x][y] == 2) {
        for (int way = 0; way < 2; way++) {
            if (sight[x][y] != '#') {
                change.push_back(make_pair(x, y));
                sight[x][y] = '#';
            }
            if (way == 0)
                for (int i = y; i < M; i++) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way == 0)
                for (int i = y; i >= 0; i--) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way == 1)
                for (int i = x; i < N; i++) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }
            if (way == 1)
                for (int i = x; i >= 0; i--) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }  
            rec(n + 1);
            for (int i = 0; i < change.size(); i++)
                sight[change[i].first][change[i].second] = 0;
            change.clear();
        }
    }
    // 1번 CCTV
    if (office[x][y] == 1) {
        for (int way = 0; way < 4; way++) {
            if (sight[x][y] != '#') {
                change.push_back(make_pair(x, y));
                sight[x][y] = '#';
            }
            if (way == 0)
                for (int i = y; i < M; i++) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way == 1)
                for (int i = y; i >= 0; i--) {
                    if (office[x][i] == 6)
                        break;
                    if (sight[x][i] != '#') {
                        change.push_back(make_pair(x, i));
                        sight[x][i] = '#';
                    }
                }
            if (way == 2)
                for (int i = x; i < N; i++) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }
            if (way == 3)
                for (int i = x; i >= 0; i--) {
                    if (office[i][y] == 6)
                        break;
                    if (sight[i][y] != '#') {
                        change.push_back(make_pair(i, y));
                        sight[i][y] = '#';
                    }
                }  
            rec(n + 1);
            for (int i = 0; i < change.size(); i++)
                sight[change[i].first][change[i].second] = 0;
            change.clear();
        } 
    }
}
