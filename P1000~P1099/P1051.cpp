#include <cstdio>
const long step[12][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-2,0},{0,2},{2,0},{0,-2} };
char M[105][105];
long n, m,s,flag[105][105];
void floodfill(long number,long x,long y) {
	flag[x][y] = s;
	for (long i = 0; i < 12; i++)
		if (x + step[i][0] > -1 && y + step[i][1] > -1 && x + step[i][0] < n  && y + step[i][1] < m  && (!flag[x + step[i][0]][y + step[i][1]]))
			floodfill(s,x+step[i][0],y+step[i][1]);
}
int main(){
	scanf("%ld%ld", &n, &m);
	for (long i = 0; i < n; i++) {
		scanf("%s", &M[i]);
		for (long j = 0; j < m; j++) if (M[i][j] == '-') flag[i][j] = -1;
	}
	for (long i = 0; i < n; i++)
		for (long j = 0; j < m; j++) {
			if (M[i][j] == '#' && (!flag[i][j])) { s++;  floodfill(s, i, j); }
		}
	printf("%ld\n", s);
}