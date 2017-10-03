#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct BigNumber {
	long len, num[35];
	inline void clear() { len = 1; memset(num,0,sizeof(num)); }															//Reset BigNumber
	inline void print() { for (long i = len; i >= 1; i--) printf("%ld", num[i]); }										//Print BigNumber
	inline BigNumber() { clear(); }																										//Initialization
	inline BigNumber(long x) { clear(); while (x) { num[len] = x % 10; x /= 10; len++; } len--; }			//Initialization
	inline BigNumber(int x) { clear(); while (x) { num[len] = x % 10; x /= 10; len++; } len--; }				//Initialization
	inline BigNumber operator + (BigNumber x) {																				//Add
		BigNumber a;
		long maxlen = max(len, x.len);
		for (long i = 1; i <= maxlen; i++) { a.num[i] += num[i] + x.num[i]; a.num[i + 1] += a.num[i] / 10; a.num[i] %= 10; }
		if (a.num[maxlen + 1]) a.len = maxlen + 1; else a.len = maxlen;
		return a;
	}
	inline BigNumber operator * (BigNumber x) {																				//Multiply
		BigNumber a;
		long maxlen = len + x.len;
		for (long i = 1; i <= len; i++) {
			for (long j = 1; j <= x.len; j++) {
				a.num[i + j - 1] += num[i] * x.num[j]; a.num[i + j] += a.num[i + j - 1] / 10; a.num[i + j - 1] %= 10;
			}
		}
		while (!a.num[maxlen]) maxlen--; 
		a.len = maxlen;
		return a;
	}
	inline bool operator == (BigNumber x) {
		if (len != x.len) return 0;
		for (long i = len; i >= 1; i--) if (num[i] != x.num[i]) return 0;
		return 1;
	}
	inline bool operator > (BigNumber x) {
		if (len > x.len) return 1; else if (len < x.len) return 0;
		for (long i = len; i >= 1; i--) if (num[i] > x.num[i]) return 1; else if (num[i] < x.num[i]) return 0;
		return 0;
	}
	inline bool operator < (BigNumber x) {
		if (len < x.len) return 1; else if (len > x.len) return 0;
		for (long i = len; i >= 1; i--) if (num[i] < x.num[i]) return 1; else if (num[i] > x.num[i]) return 0;
		return 0;
	}
};
BigNumber f[85][85], P[85], tmp, ans;
long n, m,a[85][85];
void InitPow2() {
	P[0] = 1;
	for (long i = 1; i <= 80; i++) P[i] = P[i - 1] * 2;
}
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= n; i++)
		for (long j = 1; j <= m; j++) scanf("%ld", &a[i][j]);
	InitPow2();
	for (long line = 1; line <= n; line++) {											//Work on specific line
		tmp = 0;
		for (long i = 1; i <= m; i++) {													//Choose 'i' columns			
			f[i][0] = f[i - 1][0] + P[i] * a[line][i];
			f[0][i] = f[0][i - 1] + P[i] * a[line][m-i+1];
			for (long left = 1; left <= i - 1; left++) {								//Choose 'left' columns from left side
				long right = i - left;
				if (f[left - 1][right] + P[i] * a[line][left] > f[left][right - 1] + P[i] * a[line][m - right + 1]) 
					f[left][right] = f[left - 1][right] + P[i] * a[line][left];
				else f[left][right] = f[left][right - 1] + P[i] * a[line][m - right + 1];
			}
		}
		for (long i = 0; i <= m; i++) if (tmp < f[i][m - i]) tmp = f[i][m - i];
		ans = ans + tmp;
	}
	ans.print();
}

//The origin is NOIP 2007 Senior,and it's the same as Vijos P1378.