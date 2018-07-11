#include <cstdio>
#include <algorithm>
using namespace std;
const long d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
long r, c, ans, cnt, maxx, maxy, minx, miny, m[1005][1005];
char sea[1005][1005];
inline void floodfill(long x,long y) {
	for (long i = 0; i <= 3; i++) {
		if (x + d[i][0] >= 0 && x + d[i][0] <= r - 1 && y + d[i][1] >= 0 && y + d[i][1] <= c - 1) {
			if (sea[x + d[i][0]][y + d[i][1]] == '#'&&m[x + d[i][0]][y + d[i][1]] == 0) {
				m[x + d[i][0]][y + d[i][1]] = ans, cnt++;
				maxx = max(maxx, x + d[i][0]), maxy = max(maxy, y + d[i][1]);
				minx = min(minx, x + d[i][0]), miny = min(miny, y + d[i][1]);
				floodfill(x + d[i][0], y + d[i][1]);
			}
		}
	}
}
int main() {
	scanf("%ld%ld", &r, &c);
	for (long i = 0; i < r; i++) scanf("%s", sea[i]);
	for (long i = 0; i < r; i++) {
		for (long j = 0; j < c; j++) {
			if (sea[i][j] == '#'&&m[i][j] == 0) {
				ans++, cnt = 1, maxx = minx = i, maxy = miny = j, m[i][j] = ans, floodfill(i, j);
				if (cnt != (maxx - minx + 1)*(maxy - miny + 1)) {
					printf("Bad placement.");	return 0;
				}
			}
		}
	}
	printf("%s%ld%s\n", "There are ", ans, " ships.");
}