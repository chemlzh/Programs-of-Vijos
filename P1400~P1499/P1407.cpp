#include <cstdio>
#include <algorithm>
using namespace std;
struct cloth { long num, b, v; }c[4];
struct work { long num, b, sv, v; }w[105];
long n, m, f[8005];
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= 3; i++) scanf("%ld%ld%ld", &c[i].num, &c[i].b, &c[i].v);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &w[i].v, &w[i].num);
		for (long j = 1; j <= 3; j++) {
			if (w[i].num == c[j].num) { w[i].b = w[i].v*c[j].b, w[i].sv = w[i].v*c[j].v + w[i].v; break; }
		}
	}
	for (long i = 1; i <= n; i++) {
		for (long j = m; j >= w[i].sv; j--) {
			f[j] = max(f[j], f[j - w[i].sv] + w[i].b);
		}
	}
	printf("%ld\n", f[m]);
}

/*
简单的背包问题，但是有件重要的事情要说三遍：
注意作品体积=布体积+花纹体积！！！
注意作品体积=布体积+花纹体积！！！
注意作品体积=布体积+花纹体积！！！
*/