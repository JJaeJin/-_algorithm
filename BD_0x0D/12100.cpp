#include <iostream>
#include <algorithm>

using namespace std;

int N;
int original[20][20];
int output[20][20];
int res;

void init_output(void);
void m_left(void);
void m_right(void);
void m_up(void);
void m_down(void);
void find_res(void);
void solve(int n);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> original[i][j];
    
    init_output();
    solve(0);
    cout << res;

    return 0;
}

void init_output(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            output[i][j] = original[i][j];
}

void m_left(void) {
    int temp[20][20] = {0, };
    bool v[20][20] = {0, };
    int now;
    for (int i = 0; i < N; i++) {
        now = 0;
        for (int j = 0; j < N; j++) {
            if (output[i][j] == 0)
                continue;

            if (now != 0 && output[i][j] == temp[i][now - 1] && !v[i][now - 1]) {
                temp[i][now - 1] *= 2;  
                v[i][now - 1] = 1;                  
            } else {
                temp[i][now] = output[i][j];
                now++;
            }

        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            output[i][j] = temp[i][j];
}

void m_right(void) {
    int temp[20][20] = {0, };
        bool v[20][20] = {0, };
    int now;
    for (int i = 0; i < N; i++) {
        now = N - 1;
        for (int j = N - 1; j >=0; j--) {
            if (output[i][j] == 0)
                continue;

            if (now != N - 1 && output[i][j] == temp[i][now + 1]&& !v[i][now + 1]) {
                temp[i][now + 1] *= 2;          
                v[i][now + 1] = 1;                  
            } else {
                temp[i][now] = output[i][j];
                now--;
            }
            
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            output[i][j] = temp[i][j];
}

void m_down(void) {
    int temp[20][20] = {0, };
        bool v[20][20] = {0, };
    int now;
    for (int i = 0; i < N; i++) {
        now = N - 1;
        for (int j = N - 1; j >=0; j--) {
            if (output[j][i] == 0)
                continue;


            if (now != N - 1 && output[j][i] == temp[now + 1][i]&& !v[now + 1][i]) {
                temp[now + 1][i] *= 2;      
                v[now + 1][i] = 1;                  
            } else {
                temp[now][i] = output[j][i];
                now--;
            }

        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            output[i][j] = temp[i][j];
}

void m_up(void) {
    int temp[20][20] = {0, };
        bool v[20][20] = {0, };
    int now;
    for (int i = 0; i < N; i++) {
        now = 0;
        for (int j = 0; j < N; j++) {
            if (output[j][i] == 0)
                continue;

            if (now != 0 && output[j][i] == temp[now - 1][i]&& !v[now - 1][i]) {
                temp[now - 1][i] *= 2;   
                v[now - 1][i] = 1;                  
            } else {
                temp[now][i] = output[j][i];
                now++;
            }

        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            output[i][j] = temp[i][j];
}

void find_res(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (res < output[i][j])
                res = output[i][j];
}

void solve(int n) {
    if (n == 5) {
        find_res();
        return;
    }

    int temp[20][20];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i][j] = output[i][j];

    for (int way = 0; way < 4; way++) {
        if (way == 0)
            m_up();
        else if (way == 1)
            m_right();
        else if (way == 2)
            m_down();
        else 
            m_left();

        solve(n + 1);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                output[i][j] = temp[i][j];
    }
}