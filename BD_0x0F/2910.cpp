#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, C;
map<int, int> m;
map<int, int> m_i;
vector<int> v;

bool compare(const int &a, const int &b);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int temp;
        map<int, int>::iterator map_i;
        cin >> temp;
        map_i = m.find(temp);
        v.push_back(temp);

        if (map_i == m.end()) {
            m.insert(make_pair(temp, 1));
            m_i.insert(make_pair(temp, i));
        } else {
            map_i->second++;
        }
    }

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; i++)
        cout << v[i] << ' ';

    return 0;
}

bool compare(const int &a, const int &b) {
    if (m.find(a)->second == m.find(b)->second)
        return m_i.find(a)->second < m_i.find(b)->second;
    return m.find(a)->second > m.find(b)->second;
}