#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long m[25], f[25], a[25][2], tmp, pos, cnt;
long inc, ans;
char str[200];
int main() {
	scanf("%s", &str);
	for (long i = 0; i <= strlen(str); i++) {
		if (str[i] >= '0'&&str[i] <= '9') tmp = tmp * 10 + str[i] - '0';
		else { m[++cnt] = tmp; tmp = 0; }
	}
	for (long i = 1; i <= cnt; i++) f[i] = 1;
	for (long i = 1; i <= cnt; i++) {
		for (long j = 1; j <= i - 1; j++) {
			if (m[j] > m[i]) f[i] = max(f[i], f[j] + 1);
		}
		ans = max(ans, f[i]);
		if (!inc) { a[++inc][0] = m[i]; a[inc][1] = 1; }
		else {
			tmp = 0;
			for (long j = 1; j <= inc; j++) {
				if (a[j][0] > m[i] && (a[j][0] < tmp||tmp==0)) { tmp = a[j][0]; pos = j; }
			}
			if (tmp > m[i]) { a[pos][1]++; a[pos][0] = m[i]; }
			else { a[++inc][1] = 1; a[inc][0] = m[i]; }
		}
	}
	printf("%ld,%ld", ans, inc - 1);
}