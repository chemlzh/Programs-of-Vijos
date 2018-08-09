#include <cstdio>
#include <algorithm>
using namespace std;
long n, k, ans;
long a[1005][1005], sum[1005][1005], f1[1005][1005], f2[1005][1005];
inline long calc(long row,long col) {
	if (row<k || col<k || row>n || col>n) return 0;
	return sum[row][col] + sum[row - k][col - k] - sum[row][col - k] - sum[row - k][col];
}
int main() {
	scanf("%ld%ld", &n, &k);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) {
			scanf("%ld", &a[i][j]);
			sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) {
			f1[i][j] = max(calc(i, j), max(f1[i - 1][j], f1[i][j - 1]));
		}
	}
	for (long i = n; i >= 1; i--) {
		for (long j = n; j >= 1; j--) {
			f2[i][j] = max(calc(i + k - 1, j + k - 1), max(f2[i + 1][j], f2[i][j + 1]));
		}
	}
	for (long i = 1; i <= n; i++) {
		ans = max(ans, max(f1[n][i] + f2[1][i + 1], f1[i][n] + f2[i + 1][1]));
	}
	printf("%ld", ans);
}