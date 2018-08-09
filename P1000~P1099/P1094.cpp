#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge { long u, v, w, next; }e[21005];
queue<long> q;
long n, m, u, v, w;
long head[1005], dis[1005], inq[1005], viscnt[1005], cnt, ans, flag;
inline void AddEdge(long f, long t, long d) {
	cnt++, e[cnt].u = f, e[cnt].v = t, e[cnt].w = d, e[cnt].next = head[f];
	head[f] = cnt;
}
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= n; i++) AddEdge(0, i, 0);
	for (long i = 1; i <= m; i++) {
		scanf("%ld%ld%ld", &u, &v, &w);
		if (w > 0) AddEdge(u, v, -1);
		else if (w == 0) AddEdge(u, v, 0), AddEdge(v, u, 0);
		else if (w < 0) AddEdge(v, u, -1);
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0, inq[0] = 1, viscnt[0] = 1, q.push(0);
	while (!q.empty()) {
		long tmp = q.front();
		q.pop(), inq[tmp] = 0;
		if (viscnt[tmp]++>n) {
			printf("%s", "NO"), flag = 1; break;
		}
		for (long i = head[tmp]; i != 0; i = e[i].next) {
			if (dis[e[i].v] > dis[tmp] + e[i].w) {
				dis[e[i].v] = dis[tmp] + e[i].w; 
				if (!inq[e[i].v]) inq[e[i].v] = 1, q.push(e[i].v);
			}
		}
	}
	if (!flag) {
		for (long i = 1; i <= n; i++) ans = (ans > dis[i] ? dis[i] : ans);
		printf("%ld", -ans);
	}
}