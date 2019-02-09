#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct Node { long num, dep; };
const long dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
const long MAXC = 25 * 25 + 1, MAXN = 25;
long m, n, cnt, vis[MAXN][MAXN];
long con[MAXC + 1][MAXC + 1], link[MAXC + 1][MAXC + 1], start[MAXC + 1], ter[MAXC + 1], inq[MAXC + 1];
char road[MAXN][MAXN], block[MAXC + 1];
queue <Node> q;
void floodfill(long x, long y, long num){
	long nx, ny;
	vis[x][y] = num;
	for (long i = 0; i < 4; i++) {
		nx = x + dir[i][0], ny = y + dir[i][1];
		if ((nx >= 0) && (nx <= m - 1) && (ny >= 0) && (ny <= n - 1)) {
			if ((road[nx][ny] == block[num]) && (!vis[nx][ny])) floodfill(nx, ny, num);
		}
	}
}
int main() {
	scanf("%ld%ld", &m, &n);
	for (long i = 0; i < m; i++) scanf("%s", road[i]);
	for (long i = 0; i < m; i++) {
		for (long j = 0; j < n; j++) {
			if (!vis[i][j]) cnt++, block[cnt] = road[i][j], floodfill(i, j, cnt);
		}
	}
	for (long i = 0; i < m; i++) {
		for (long j = 0; j < n; j++) {
			if ((!i)&&(!ter[vis[i][j]])) ter[vis[i][j]] = 1;
			if ((i == m - 1) && (!start[vis[i][j]])) {
				Node nd;
				nd.dep = 1, nd.num = vis[i][j], q.push(nd), start[vis[i][j]] = 1, inq[vis[i][j]] = 1;
			}
			if ((i < m - 1) && (vis[i][j] != vis[i + 1][j]) && (!con[vis[i][j]][vis[i + 1][j]])) {
				con[vis[i][j]][vis[i + 1][j]] = con[vis[i + 1][j]][vis[i][j]] = 1;
				link[vis[i][j]][0]++, link[vis[i][j]][link[vis[i][j]][0]] = vis[i + 1][j];
				link[vis[i + 1][j]][0]++, link[vis[i + 1][j]][link[vis[i + 1][j]][0]] = vis[i][j];
			}
			if ((j < n - 1) && (vis[i][j] != vis[i][j + 1]) && (!con[vis[i][j]][vis[i][j + 1]])) {
				con[vis[i][j]][vis[i][j+1]] = con[vis[i][j+1]][vis[i][j]] = 1;
				link[vis[i][j]][0]++, link[vis[i][j]][link[vis[i][j]][0]] = vis[i][j + 1];
				link[vis[i][j + 1]][0]++, link[vis[i][j + 1]][link[vis[i][j + 1]][0]] = vis[i][j];
			}
 		}
	}	
	while (!q.empty()) {
		Node tmp = q.front(), tmp1; q.pop();
		if (ter[tmp.num]) { printf("%ld\n", tmp.dep); break; }
		for (long i = 1; i <= link[tmp.num][0]; i++) {
			if (!inq[link[tmp.num][i]]) {
				inq[link[tmp.num][i]] = 1;
				tmp1.num = link[tmp.num][i], tmp1.dep = tmp.dep + 1, q.push(tmp1);
			}
		}
	}
}