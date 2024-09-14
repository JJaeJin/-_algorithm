#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int A, B, C;
long long mod(long long a, long long b, long long c);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;
	cout << mod(A, B, C);

	return 0;
}

long long mod(long long a, long long b, long long c) {
	if (b == 1)
		return a % c;
	long long res = mod(a, b / 2, c);
	res = res * res % c;
	if (b % 2 == 0)
		return res;
	return res * a % c;
}