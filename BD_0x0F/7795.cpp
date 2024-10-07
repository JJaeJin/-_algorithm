#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int total, N, M;
vector<int> a, b;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> total;
    while (total--) {
        cin >> N >> M;
        int temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < M; i++) {
            cin >> temp;
            b.push_back(temp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int res = 0;
        int ai = 0, bi = 0;
        while (ai != a.size()) {
            while (bi != b.size() && a[ai] > b[bi])
                bi++;
            res += bi;
            ai++;
        }
        cout << res << '\n';
        a.clear();
        b.clear();
    }
    return 0;
}