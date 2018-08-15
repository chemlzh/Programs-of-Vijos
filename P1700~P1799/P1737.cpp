#include <cstdio>
long n, k, p, color, cost, tmp, c1[55], c2[55], c3[55], ans;
int main() {
	scanf("%ld%ld%ld", &n, &k, &p);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &color, &cost);
		if (cost <= p) tmp = i;
		if (c3[color] <= tmp) c2[color] = c1[color];
		c3[color] = i, ans += c2[color], c1[color]++;
	}
	printf("%ld\n", ans);
}
//c1: the sum of hotel whose color is 'color'.
//c2: the sum of hotel which has a cheap cafe on the way and whose color is 'color'.
//c3: the position of last hotel whose color is 'color'.
//tmp: the position of hotel which has a cheap cafe.