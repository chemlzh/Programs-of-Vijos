#include <cstdio>
const long ModNum = 10007;
long a, b, k, n, m;
long c[1005];
inline long fastpower(long x, long y) {
	if (y == 0) return 1;
	else if (y == 1) return x % ModNum;
	long tmp = fastpower(x, y / 2);
	tmp = (tmp*tmp) % ModNum;
	if (y % 2 == 0) return tmp;
	else return (tmp*x) % ModNum;
}
inline long combination(long k0, long n0) {
	c[1] = 1;
	for (long i = 1; i <= n0; i++) {
		for (long j = i + 1; j >= 1; j--) c[j] = (c[j] + c[j - 1]) % ModNum;
	}
	return c[k0 + 1];
}
int main() {
	scanf("%ld%ld%ld%ld%ld", &a, &b, &k, &n, &m);
	printf("%ld", ((fastpower(a, n)*fastpower(b, m)) % ModNum*combination(n, k)) % ModNum);
}