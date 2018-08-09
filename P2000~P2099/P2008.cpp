#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const double eps = 1e-10;
const long INF = 0x7fffffff;
struct point { double x, y; }p[20];
long T, n, m, cnt, ans, f[1000], step[(1 << 18) + 1];
queue<long> q;
inline void calc(point a,point b) {
	long tmp = 0;
	if (a.x == b.x&&a.y != b.y) return;
	double aa = (a.y*b.x - a.x*b.y) / (a.x*a.x*b.x - b.x*b.x*a.x), 
		bb = (b.y*a.x*a.x-a.y*b.x*b.x)/ (a.x*a.x*b.x - b.x*b.x*a.x);
	if (aa >= 0) return;
	for (long i = 1; i <= n; i++) {
		if (fabs(aa*p[i].x*p[i].x + bb * p[i].x - p[i].y) <= eps) tmp |= 1 << (i - 1);
	}
	f[++cnt] = tmp;
}
inline void bfs() {
	while (!q.empty()) q.pop();
	memset(step, 0, sizeof(step));
	for (long i = 1; i <= cnt; i++) step[f[i]] = 1, q.push(f[i]);
	long cc;
	while (!q.empty()) {
		cc = q.front(), q.pop();
		if (cc == (1 << n) - 1) {
			ans = step[cc]; break;
		}
		for (long i = 1; i <= cnt; i++) {
			if (!step[cc | f[i]]) step[cc | f[i]] = step[cc] + 1, q.push(cc | f[i]);
		}
	}
}
int main() {
	scanf("%ld", &T);
	while (T--) {
		cnt = 0, ans = INF;
		scanf("%ld%ld", &n, &m);
		for (long i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
		for (long i = 1; i <= n; i++) {
			for (long j = i + 1; j <= n; j++) calc(p[i], p[j]);
			f[++cnt] = 1 << (i - 1);
		}
		bfs();
		printf("%ld\n", ans);
	}
}