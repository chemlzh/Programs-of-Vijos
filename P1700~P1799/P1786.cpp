#include <cstdio>
#include <cmath>
long n;
int main() {
	scanf("%ld", &n);
	if (n % 2 == 0) { printf("%ld\n", n / 2); return 0; }
	for (long i = 3; i <= sqrt(n); i+=2)
		if (n%i == 0) { printf("%ld\n", n / i); return 0; }
}