#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
struct peanut { long x, y, c; }p[625];
long m, n, k, cnt, ans, used;
long a[25][25];
inline bool cmp(peanut a,peanut b) { return a.c > b.c; }
int main() {
	scanf("%ld%ld%ld", &m, &n, &k);
	for (long i = 1; i <= m; i++) {
		for (long j = 1; j <= n; j++) {
			scanf("%ld", &a[i][j]);
			if (a[i][j]) cnt++, p[cnt].x = i, p[cnt].y = j, p[cnt].c = a[i][j];
		}
	}
	sort(p + 1, p + cnt + 1, cmp);
	if (2 * p[1].x >= k) { printf("%ld", 0L); return 0; }
	else {
		ans += p[1].c, used += p[1].x + 1;
		for (long i = 2; i <= cnt; i++) {
			used += abs(p[i].x - p[i - 1].x) + abs(p[i].y - p[i - 1].y) + p[i].x + 1;
			if (k >= used) { ans += p[i].c, used -= p[i].x; }
			else break;
		}
		printf("%ld", ans);
	}
}