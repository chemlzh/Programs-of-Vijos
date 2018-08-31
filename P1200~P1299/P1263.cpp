#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct pos { long x, y; }thief, swordsman;
const long dir[8][2] = { {-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,-1},{1,1},{-1,1} };
long m, n, flag, ans;
long vis[20005], appro[20005];
char map[20005], c;
queue <pos> q;
inline void mark() {	//Pretreatment of possible position.
	pos t;
	appro[(thief.x - 1)*m + thief.y] = 1;
	for (long i = 0; i < 8; i++) {
		t = thief;
		while (t.x >= 1 && t.x <= n && t.y >= 1 && t.y <= m && map[(t.x - 1)*m + t.y] == 'O') {
			appro[(t.x - 1)*m + t.y] = 1, t.x += dir[i][0], t.y += dir[i][1];
		}
	}
}
inline void bfs() {
	vis[(swordsman.x - 1)*m + swordsman.y] = 1, q.push(swordsman);
	while (!q.empty()) {
		pos t = q.front(), t1;
		q.pop();
		if (appro[(t.x - 1)*m + t.y]) { flag = 1, ans = vis[(t.x - 1)*m + t.y] - 1; break; }
		for (long i = 0; i < 4; i++) {
			t1.x = t.x + dir[i][0], t1.y = t.y + dir[i][1];
			//Pay attention to vis[(t1.x - 1)*m + t1.y].
			//If (t1.x, t1.y) is visited, don't add it to the queue.
			if (t1.x >= 1 && t1.x <= n && t1.y >= 1 && t1.y <= m && map[(t1.x - 1)*m + t1.y] == 'O' && (!vis[(t1.x - 1)*m + t1.y])) {
				vis[(t1.x - 1)*m + t1.y] = vis[(t.x - 1)*m + t.y] + 1, q.push(t1);
			}
		}
	}
	if (flag) printf("%ld\n", ans);
	else printf("%s\n", "Impossible!");
	while (!q.empty()) q.pop();
}
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= n; i++) {
		scanf("%c", &c);
		for (long j = 1; j <= m; j++) scanf("%c", &map[(i - 1)*m + j]);
	}
	while (true) {
		scanf("%ld%ld%ld%ld", &thief.x, &thief.y, &swordsman.x, &swordsman.y);
		if (thief.x == 0 && thief.y == 0 && swordsman.x == 0 && swordsman.y == 0) break;
		memset(vis, 0, sizeof(vis)), memset(appro, 0, sizeof(appro)), flag = 0, ans = 0;
		mark(),	bfs();
	}
}