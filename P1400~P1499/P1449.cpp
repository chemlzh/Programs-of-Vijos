#include <cstdio>
#include <cstring>
const long check[6][3] = { {0,4,8},{0,5,7},{1,3,8},{1,5,6},{2,3,7},{2,4,6} };
long n;
char s[3][10005], t[9][10005];
int main() {
	scanf("%ld", &n);
	for (long i = 0; i <= 2; i++) {
		scanf("%s", s[i]);
		for (long j = 0; j <= n - 1; j++) t[3 * i][j] = s[i][n - j - 1];
	}
	for (long k = 0; k <= 6; k++) {
		long flag = 0;
		for (long i = 0; i <= 2; i++) {
			for (long j = 0; j <= n - 1; j++) {
				t[3 * i + 1][j] = (s[i][j] - 'a' + k) % 26 + 'a';
				t[3 * i + 2][j] = (s[i][j] - 'a' - k + 26) % 26 + 'a';
			}
		}
		for (long i = 0; i <= 5; i++) {
			if (strcmp(t[check[i][0]], t[check[i][1]]) == 0 && strcmp(t[check[i][1]], t[check[i][2]]) == 0) {
				printf("%s", t[check[i][0]]), flag = 1;
				break;
			}
		}
		if (flag) break;
	}
}