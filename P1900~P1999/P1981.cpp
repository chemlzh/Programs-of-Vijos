#include <cstdio>
long L, N, M, stone[50005];
bool check(long mdis) {
	long pos = 0, cnt = 0;
	for (long i = 1; i <= N + 1; i++) {
		if (stone[i] - pos >= mdis) pos = stone[i];
		else {
			cnt++;
			if (cnt > M) return false;
		}
	}
	return true;
}
int main() {
	scanf("%ld%ld%ld", &L, &N, &M);
	for (long i = 1; i <= N; i++) scanf("%ld", &stone[i]);
	stone[N + 1] = L;
	long left = 1, right = L, mid, ans = 0;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (check(mid)) left = mid + 1, ans = mid; else right = mid - 1;
	}
	printf("%ld\n", ans);
}