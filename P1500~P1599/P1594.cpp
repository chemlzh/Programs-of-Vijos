#include <cstdio>
#include <algorithm>
using namespace std;
long n, v, k, tmp, speed[105], dp[105][205];
double s;
int main() {
	scanf("%ld%ld%ld", &n, &v, &k);
	for (long i = 2; i <= n; i++) scanf("%ld", &speed[i]);
	if (speed[n] > v || speed[n] < v - k) printf("%s", "REN JIU SHI BU NENG REN CI! ");
	else {
		dp[n][v] = v;
		for (long i = n - 1; i >= 2; i--) {
			for (long j = speed[i]; j <= speed[i] + k; j++) {
				tmp = max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j - 1]));
				if (tmp) dp[i][j] = tmp + j;
			}
		}
		for (long i = speed[2]; i <= speed[2] + k; i++) s = max(s, (double)dp[2][i]);
		if (!s) printf("%s", "REN JIU SHI BU NENG REN CI! ");
		else printf("%.2f\n", s / (n - 1));
	}
}