#include <cstdio>
const long power3[17] = { 1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721 };
long N;
int main() {
	scanf("%ld", &N);
	for (long i = 0; i <= 15; i++) {
		if ((N > power3[i]) && (N <= power3[i + 1])) printf("%ld\n", i + 1);
	}
}