#include <cstdio>
#include <cstring>
#include <cmath>
long n;
double a[105][106], t[106];
inline void swap(long r1, long r2) {
	memcpy(t, a[r1], sizeof(a[r1]));
	memcpy(a[r1], a[r2], sizeof(a[r2]));
	memcpy(a[r2], t, sizeof(t));
}
inline void gauss() {
	long tmp;
	double f;
	for (long i = 1; i <= n; i++) {
		tmp = i;
		for (long j = i + 1; j <= n; j++) {
			if (fabs(a[j][i]) > fabs(a[tmp][i])) tmp = j;
		}
		if (tmp != i) swap(tmp, i);
		for (long j = i + 1; j <= n; j++) {
			f = a[j][i] / a[i][i];
			for (long k = i; k <= n + 1; k++) a[j][k] -= f * a[i][k];
		}
	}
	for (long i = n; i >= 1; i--) {
		for (long j = i + 1; j <= n; j++) a[i][n + 1] -= a[i][j] * a[j][n + 1];
		a[i][n + 1] /= a[i][i];
	}
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n + 1; j++) scanf("%lf", &a[i][j]);
	}
	gauss();
	for (long i = 1; i < n; i++) printf("%ld ", (long)round(a[i][n + 1]));
	printf("%ld\n", (long)round(a[n][n + 1]));
}