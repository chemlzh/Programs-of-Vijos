#include <cstdio>
#include <cstring>
#include <cmath>
const long prime[18] = { 0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59 };
long n, k, l, flag, ans[18], tmp[18], fac[1005];
double minres;
inline long isprime(long num) {
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (long i = 3; i*i <= num; i += 2) {	if (num%i == 0) return false; }
	return true;
}
inline void dfs(long last, long now, long step, double res) {
	if (res > minres) return;
	if (now == 1) {
		if (res < minres) minres = res, memcpy(ans, tmp, sizeof(tmp));
		return;
	}
	if (step > 16) return;
	for (long i = last; i >= 1; i--) {
		if (now%fac[i] == 0) {
			tmp[step] = fac[i];
			dfs(i, now / fac[i], step + 1, res + log(prime[step])*(fac[i] - 1));
			tmp[step] = 0;
		}
	}
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &k);
		if (k == 1) printf("%ld\n", 1L);
		else if (isprime(k)) printf("%ld%c%ld\n", 2, '^', k - 1);
		else {
			memset(ans, 0, sizeof(ans)), memset(tmp, 0, sizeof(tmp));
			for (long j = 2; j <= k - 1; j++) { if (k%j == 0) fac[++l] = j; }
			minres = 1 << 20, dfs(l, k, 1, 0), flag = 0;
			for (long j = 1; j <= 17; j++) {
				if (ans[j]) {
					if (flag) printf("*");
					printf("%ld", prime[j]);
					if (ans[j] > 2) printf("%c%ld", '^', ans[j] - 1);
					flag = 1;
				}
			}
			printf("\n");
		}
	}
}