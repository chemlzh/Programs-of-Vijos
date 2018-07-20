#include <cstdio>
long long n, m, fac, ans;
int main() {
	scanf("%lld%lld", &n, &m), fac = 1;
	for (long i = 1; i <= (n > m ? m : n); i++) fac = (fac*i) % m, ans = (ans + fac) % m;
	printf("%lld", ans);
}