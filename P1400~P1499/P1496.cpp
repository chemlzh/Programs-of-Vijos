#include <cstdio>
const long match[10] = { 6,2,5,5,4,5,6,3,7,6 };
long n, ans;
inline long work(long num) {
	if (!num) return match[0];
	else {
		long tmp = 0;
		while (num) tmp += match[num % 10], num /= 10;
		return tmp;
	}
}
int main() {
	scanf("%ld", &n);
	for (long i = 0; i <= 1111; i++) {
		for (long j = 0; j <= 1111; j++) {
			if (work(i) + work(j) + work(i + j) + 4 == n) ans++;
		}
	}
	printf("%ld\n", ans);
}