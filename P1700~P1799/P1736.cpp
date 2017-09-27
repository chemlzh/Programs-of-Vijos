#include <cstdio>
struct carpet { long a, b, g, k; }c[10005];
long n, ans,x,y;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld%ld%ld", &c[i].a, &c[i].b, &c[i].g, &c[i].k);
	scanf("%ld%ld", &x, &y);
	for (long i = n; i >= 1; i--) if (x >= c[i].a&&x <= c[i].a + c[i].g&&y >= c[i].b&&y <= c[i].b + c[i].k) { printf("%ld\n", i); return 0; }
	printf("%ld\n", -1);
}