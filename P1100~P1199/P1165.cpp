#include <cstdio>
#include <algorithm>
using namespace std;
struct ship { long left, right; }s[20005];
long n, ans, l, r;
inline bool cmp(const ship &a, const ship &b) {
	if (a.left < b.left) return 1;
	else if (a.left > b.left) return 0;
	else if (a.right < b.right) return 1;
	else return 0;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld", &s[i].left, &s[i].right);
	sort(s + 1, s + n + 1, cmp), l = s[1].left, r = s[1].right;
	for (long i = 2; i <= n; i++) {
		if (s[i].left <= r) {
			if (s[i].right > r) r = s[i].right;
		}
		else ans += r - l, l = s[i].left, r = s[i].right;
	}
	ans += r - l;
	printf("%ld\n", ans);
}