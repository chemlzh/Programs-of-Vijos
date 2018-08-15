#include <cstdio>
#include <algorithm>
using namespace std;
long n, m, r, money[105], rp[105], time[1005], f[105][105], t[105][105];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld%ld", &money[i], &rp[i], &time[i]);
	scanf("%ld%ld", &m, &r);
	for (long i = 1; i <= n; i++) {
		for (long j = m; j >= money[i]; j--) {
			for (long k = r; k >= rp[i]; k--) {
				if (f[j][k] < f[j - money[i]][k - rp[i]] + 1) {
					f[j][k] = f[j - money[i]][k - rp[i]] + 1;
					t[j][k] = t[j - money[i]][k - rp[i]] + time[i];
				}
				else if (f[j][k] == f[j - money[i]][k - rp[i]] + 1) {
					t[j][k] = min(t[j][k], t[j - money[i]][k - rp[i]] + time[i]);
				}
			}
		}
	}
	printf("%ld\n", t[m][r]);
}