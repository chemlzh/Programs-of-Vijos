#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge { long u, v, cap, flow; }edge[1005];
const long INF = 100005;
long n, e, m, from, to, value, terminal, cnt;
long Head[105], Next[1005], Depth[105], Cur[105];
inline void AddEdge(long from, long to, long value) {		// Add an edge to the graph.
	cnt++, edge[cnt].u = from, edge[cnt].v = to, edge[cnt].cap = value;
	Next[cnt] = Head[from], Head[from] = cnt;
}
inline long BFS() {		// Use BFS to build a level graph.
	queue<long> q;
	while (!q.empty()) q.pop();
	memset(Depth, 0, sizeof(Depth));
	Depth[1] = 1, q.push(1);
	while (!q.empty()) {
		long u = q.front();
		q.pop();
		for (long i = Head[u]; i != 0; i = Next[i]) {
			if (edge[i].cap > edge[i].flow && (!Depth[edge[i].v])) {
				// Consider edges with residual capacity only.
				Depth[edge[i].v] = Depth[u] + 1;
				q.push(edge[i].v);
			}
		}
	}
	if (!Depth[n + 1]) return 0;
	return 1;
}
inline long DFS(long s,long f) {		// Use DFS to find a blocking flow.
	if (s == n + 1) return f;
	for (long& i = Cur[s]; i != 0; i = Next[i]) {
		if ((Depth[s] + 1 == Depth[edge[i].v]) && (edge[i].cap > edge[i].flow)) {
			// Consider edges with residual capacity only.
			// Noted that edges must satisfy with depth[s]+1==depth[t].
			long dis = DFS(edge[i].v, min(f, edge[i].cap - edge[i].flow));
			if (dis > 0) {
				edge[i].flow += dis, edge[i + 1].flow -= dis;
				return dis;
			}
		}
	}
	return 0;
}
inline long Dinic() {		// Dinic's algorithm.
	long ans = 0;	// 'ans' means the value of max flow.
	while (BFS()) {
		for (long i = 1; i <= n + 1; i++) Cur[i] = Head[i];		// Set current edge to the 'head' edge.
		ans += DFS(1, INF);
	}
	return ans;
}
int main() {
	scanf("%ld%ld", &n, &e);
	for (long i = 1; i <= e; i++) {
		scanf("%ld%ld%ld", &from, &to, &value), AddEdge(from, to, value), AddEdge(to, from, value);
	//	scanf("%ld%ld%ld", &edge[2 * i - 1].u, &edge[2 * i - 1].v, &edge[2 * i - 1].cap);
	//	edge[2 * i].u = edge[2 * i - 1].v, edge[2 * i].v = edge[2 * i - 1].u, edge[2 * i].cap = edge[2 * i - 1].cap;
	}
	scanf("%ld", &m);
	for (long i = 1; i <= m; i++) {
		scanf("%ld", &terminal), AddEdge(terminal, n + 1, INF);
	//	edge[2 * e + i].u = terminal, edge[2 * e + i].v = n + 1, edge[2 * e + i].cap = INF;
	}
	printf("%ld\n", Dinic());
}