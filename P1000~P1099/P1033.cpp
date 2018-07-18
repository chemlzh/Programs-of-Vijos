#include <cstdio>
#include <cstring>
class BigDecimal {
public:
	long digit[250], len;
	BigDecimal() { memset(digit, 0, sizeof(digit)), len = 1; }
	BigDecimal(long num) { standardize(num); }
	BigDecimal & operator =(long num) { standardize(num); return *this; }
	BigDecimal & operator =(BigDecimal bd) {
		len = bd.len, memcpy(digit, bd.digit, sizeof(bd.digit));
		return *this;
	}
	BigDecimal operator *(long num) {
		BigDecimal res;
		for (long i = 0; i <= len - 1; i++) res.digit[i] += digit[i] * num, res.digit[i + 1] += res.digit[i] / 10, res.digit[i] %= 10;
		res.len = len;
		while (res.digit[res.len]) res.digit[res.len + 1] += res.digit[res.len] / 10, res.digit[res.len++] %= 10;
		return res;
	}
	BigDecimal & operator *=(long num) {
		*this = *this * num;
		return *this;
	}
	void standardize(long num) {
		memset(digit, 0, sizeof(digit)), len = 0;
		if (num) {
			while (num) digit[len++] = num % 10, num /= 10;
		}
		else len++;
	}
	void print() {
		for (long i = len - 1; i >= 0; i--) printf("%ld", digit[i]);
	}
};
long n, p2, p3;
int main() {
	scanf("%ld", &n);
	if (n % 3 == 1&&n > 1) p2 = 2, p3 = n / 3 - 1;
	else if (n%3==2) p2 = 1, p3 = n / 3;
	else p2 = 0, p3 = n / 3;
	BigDecimal ans = 1;
	for (long i = 1; i <= p3; i++) ans *= 3;
	for (long i = 1; i <= p2; i++) ans *= 2;
	ans.print();
}