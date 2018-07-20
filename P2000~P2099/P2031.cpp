#include <cstdio>
struct Point { unsigned long long x, y, z; }p[1005];
long T, n, father[1005];
unsigned long long h, r, rr;
inline void init(long cnt) {
	for (long i = 0; i <= cnt + 1; i++) father[i] = i;
}
inline long find(long a) {
	if (a != father[a]) father[a] = find(father[a]);
	return father[a];
}
inline void unite(long a, long b) {
	long fa = find(a), fb = find(b);
	father[fb] = fa;
}
inline bool check(Point a, Point b) {
	return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z) <= rr);
}
int main() {
	scanf("%ld", &T);
	for (long i = 1; i <= T; i++) {
		scanf("%ld%lld%lld", &n, &h, &r), init(n), rr = 4 * r*r;
		for (long j = 1; j <= n; j++) {
			scanf("%lld%lld%lld", &p[j].x, &p[j].y, &p[j].z);
			if (p[j].z <= r) unite(0, j);
			if (p[j].z + r >= h) unite(j, n + 1);
		}
		for (long j = 1; j <= n; j++) {
			for (long k = j + 1; k <= n; k++) {
				if (check(p[j], p[k])) unite(j, k);
			}
		}
		if (find(0) == find(n + 1)) printf("%s\n", "Yes");
		else printf("%s\n", "No");
	}
}