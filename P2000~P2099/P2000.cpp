#include <cstdio>
#include <cstring>
const long MAXN = 5005;
const long BASE[9] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000 };
char a[5005], b[5005];
unsigned long long num1[640], num2[640],num3[1280];
long n, lena, lenb;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%s%s", a, b);
		lena = strlen(a); lenb = strlen(b);
		for (long j = lena - 1; j >= 0; j--) {
			if ((lena - j) % 8 == 1) num1[0]++;
			num1[num1[0]] += (a[j] - '0')*BASE[(lena - j - 1) % 8];
		}
		for (long j = lenb - 1; j >= 0; j--) {
			if ((lenb - j) % 8 == 1) num2[0]++;
			num2[num2[0]] += (b[j] - '0')*BASE[(lenb - j - 1) % 8];
		}
		num3[0] = num1[0] + num2[0];
		for (long j = 1; j <= num1[0]; j++) {
			for (long k = 1; k <= num2[0]; k++) num3[j + k - 1] += num1[j] * num2[k];
		}
		for (long j = 1; j <= num3[0]; j++) { 
			num3[j + 1] += num3[j] / BASE[8]; num3[j] %= BASE[8];
		}
		while (!num3[num3[0]]&&num3[0]>1) num3[0]--;
		printf("%lld", num3[num3[0]]);
		for (long j = num3[0] - 1; j >= 1; j--) {
			for (long k = 7; k >= 0; k--) {
				if (num3[j] >= BASE[k]) { printf("%lld", num3[j]); break; }
				else printf("%ld", 0L);
			}
		}
		printf("\n");
		memset(a, '\0', sizeof(a));	memset(b, '\0', sizeof(b));
		memset(num1, 0, sizeof(num1)); memset(num2, 0, sizeof(num2)); 
		memset(num3, 0, sizeof(num3));
	}
}