#include <cstdio>
struct people { long f; char name[12]; }p[100005];
long n, m, ans;
long ai, si;
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 0; i < n; i++) scanf("%ld%s", &p[i].f, p[i].name);
	for (long i = 1; i <= m; i++) {
		scanf("%ld%ld", &ai, &si);
		if ((p[ans].f + ai) % 2 == 0) ans = (ans + n - si) % n;
		else if ((p[ans].f + ai) % 2 == 1) ans = (ans + n + si) % n;
	}
	printf("%s\n", p[ans].name);
}