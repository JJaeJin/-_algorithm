// O(N)
int func1(int N) {
	int res = 0;

	for (int i = 0; i <= N; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			res++;
	}
	return res;
}

// O(N^2)
int func2(int arr[], int N) {
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (arr[i] + arr[j] == 100)
				return 1;
	return 0;
}

// O(lgN)
int func3(int N) {
	for (int i = 1; i * i <= N; i++)
		if (i * i == N)
			return 1;
	return 0;
}

// O(lgN)
int func4(int N) {
	int res;

	for (res = 1; res <= N; res *= 2) {
		if (res == N)
			break;
	}
	return res / 2;
}