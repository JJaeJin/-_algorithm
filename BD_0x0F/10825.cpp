#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b);

int N;
vector<tuple<string, int, int, int> > v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        int i1, i2, i3;
        cin >> s >> i1 >> i2 >> i3;
        v.push_back(make_tuple(s, i1, i2, i3));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
        cout << get<0>(v[i]) << '\n';

    return 0;
}

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
    auto [s1, a1, a2, a3] = a;
    auto [s2, b1, b2, b3] = b;
    
    if (a1 != b1)
        return a1 > b1;
    if (a2 != b2)
        return a2 < b2;
    if (a3 != b3)
        return a3 > b3;
    return s1 < s2;
}