#include <cstdio>
#include <algorithm>
using namespace std;
long n, v0, k, flag, v[20005];
int main() {
	scanf("%ld%ld%ld", &n, &v0, &k), v[1] = v0;
	for (long i = 2; i <= n; i++) scanf("%ld", &v[i]);
	sort(v + 1, v + n + 1);
	for (long i = 2; i <= n; i++) {
		if (v[n] - v[i] <= k && v[i - 1] - v[1] <= k) { flag = 1; break; }
	}
	if (flag) printf("%s", "Yes");
	else printf("%s", "No");
}