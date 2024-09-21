#include <iostream>
#include <algorithm>

using namespace std;

// C개의 알파벳 중 L개로 이루어진 암호
// 최소 두 개의 자음, 한 개의 모음 (a, e, i, o, u)
int L, C;
char arr[15];
char res[15];
// 자음 = consonant, 모음 = vowel
int con, vow;

void rec(int n, int start);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> arr[i];
    sort(arr, arr + C);
    rec(0, 0);
    return 0;
}

void rec(int n, int start) {
    if (n == L) {
        if (con  >= 2 && vow >= 1) {
            for (int i = 0; i < L; i++)
                cout << res[i];
            cout << '\n';
        }
        return;
    }

    for (int i = start; i < C; i++) {
        if (n == 0) {
            con = 0;
            vow = 0;
        }
        res[n] = arr[i];
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            vow++;
        else
            con++;
        rec(n + 1, i + 1);
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            vow--;
        else
            con--;
    }
}