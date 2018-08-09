#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long n, ans, f[2005];
char s[2005][80];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%s", s[i]), f[i] = 1;
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j < i; j++) {
			if (strstr(s[i], s[j]) == s[i]) f[i] = max(f[j] + 1, f[i]);
		}
	}
	for (long i = 1; i <= n; i++) ans = max(ans, f[i]);
	printf("%ld\n", ans);
}