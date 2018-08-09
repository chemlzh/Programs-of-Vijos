#include <cstdio>
#include <algorithm>
using namespace std;
long n, m, ans;
long f[305][305], s[305][305], h[305][305], l[305][305], r[305][305];
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= m; j++) {
			scanf("%ld", &f[i][j]);
			s[i][j] = f[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			if (f[i][j]) h[i][j] = h[i - 1][j] + 1;
		}
		long left = 1, right = m, tmp;
		for (long j = 1; j <= m; j++) {
			if (!f[i][j]) left = j + 1;
			else if (!f[i - 1][j]) l[i][j] = left;
			else l[i][j] = max(l[i - 1][j], left);
		}
		for (long j = m; j >= 1; j--) {
			if (!f[i][j]) right = j - 1;
			else if (!f[i - 1][j]) r[i][j] = right;
			else r[i][j] = min(r[i - 1][j], right);
		}
		for (long j = 1; j <= m; j++) {
			tmp = s[i][r[i][j]] - s[i][l[i][j] - 1] - s[i - h[i][j]][r[i][j]] + s[i - h[i][j]][l[i][j] - 1];
			ans = max(ans, tmp);
		}
	}
	printf("%ld\n", ans);
}