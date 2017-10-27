#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long m[25], f[25][2], tmp, cnt;
long inc,ans;
char str[200];
int main() {
	scanf("%s", &str);
	for (long i = 0; i <= strlen(str); i++) {
		if (str[i] >= '0'&&str[i] <= '9') tmp = tmp * 10 + str[i] - '0';
		else { m[++cnt] = tmp; tmp = 0; }
	}
	if (cnt == 1) { printf("%ld,%ld", 1L, 0L); return 0; }
	for (long i = 1; i <= cnt; i++) f[i][0] = f[i][1] = 1;
	for (long i = 2; i <= cnt; i++) {
		for (long j = 1; j <= i - 1; j++) {
			if (m[j] >= m[i]) f[i][0] = max(f[i][0], f[j][0] + 1);
			if (m[j] < m[i]) f[i][1] = max(f[i][1], f[j][1] + 1);
		}
		ans = max(ans,f[i][0]); inc = max(inc, f[i][1]);
	}	
	printf("%ld,%ld", ans, inc-1);
}