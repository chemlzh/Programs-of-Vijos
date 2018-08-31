#include <cstdio>
long long res[25][25][25];
long a, b, c;
inline long long dfs(long A, long B, long C) {
	if (A <= 0 || B <= 0 || C <= 0) return 1;
	else if (A > 20 || B > 20 || C > 20) return dfs(20, 20, 20);
	else if (res[A][B][C]) return res[A][B][C];
	else if (A < B&&B < C) {
		res[A][B][C] = dfs(A, B, C - 1) + dfs(A, B - 1, C - 1) - dfs(A, B - 1, C);
		return res[A][B][C];
	}
	else {
		res[A][B][C] = dfs(A - 1, B, C) + dfs(A - 1, B - 1, C) + dfs(A - 1, B, C - 1) - dfs(A - 1, B - 1, C - 1);
		return res[A][B][C];
	}
}
int main() {
	while (scanf("%ld%ld%ld", &a, &b, &c) == 3) {
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%ld, %ld, %ld) = %lld\n", a, b, c, dfs(a, b, c));
	}
}