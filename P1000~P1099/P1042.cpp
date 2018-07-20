#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const long firststep[4] = { 1,3,7,9 };
long m, n, ans[10005], cnt;
inline bool isprime(long num) {
	if (num == 0 || num == 1) return false;
	if (num % 2 == 0) return false;
	for (long i = 3; i <= sqrt(num); i += 2) {
		if (num%i == 0) return false;
	}
	return true;
}
inline long transform(bool method, long num) {
	long tmp = num;
	if (method) num /= 10;
	while (num) tmp = tmp * 10 + num % 10, num /= 10;
	return tmp;
}
inline void dfs(long tmp) {
	long res1 = transform(1, tmp), res2 = transform(0, tmp);
	if (res1 > n) return;
	else if (res2 < m) {
		for (long i = 0; i <= 9; i++) dfs(tmp * 10 + i);
	}
	else {
		if (res1 >= m && res1 <= n && isprime(res1)) ans[++cnt] = res1;
		if (res2 >= m && res2 <= n && isprime(res2)) ans[++cnt] = res2;
		for (long i = 0; i <= 9; i++) dfs(tmp * 10 + i);
	}
}
int main() {
	scanf("%ld%ld", &m, &n);
	if (m <= 2 && n >= 2) ans[++cnt] = 2;
	if (m <= 5 && n >= 5) ans[++cnt] = 5;
	for (long i = 0; i <= 3; i++) dfs(firststep[i]);
	sort(ans + 1, ans + cnt + 1);
	for (long i = 1; i <= cnt; i++) printf("%ld\n", ans[i]);
}