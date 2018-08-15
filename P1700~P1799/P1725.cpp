#include <cstdio>
#include <cstring>
class Matrix {
public:
	long row, col;
	long long f[3][3];
	Matrix(long r, long c) :row(r), col(c) { memset(f, 0, sizeof(f)); }
	friend Matrix operator  * (Matrix m1, Matrix m2);
	friend Matrix operator ^ (Matrix m, long long p);
};
long long m, a, c, x0, n, g;
Matrix X(1, 2), B(2, 2), Ans(1, 2);
inline void init() {
	X.f[0][0] = x0, X.f[0][1] = c, B.f[0][0] = a, B.f[1][0] = B.f[1][1] = 1;
}
inline long long mul(long long l1,long long l2) {
	long long res = 0;
	while (l2) {
		if (l2 & 1) res = (res + l1) % m;
		l1 = (l1 + l1) % m;
		l2 >>= 1;
	}
	return res;
}
Matrix operator * (Matrix m1, Matrix m2) {
	Matrix res(m1.row, m2.col);
	for (long i = 0; i < res.row; i++) {
		for (long j = 0; j < res.col; j++) {
			for (long k = 0; k < m1.col; k++) {
				res.f[i][j] += mul(m1.f[i][k], m2.f[k][j]), res.f[i][j] %= m;
				if (res.f[i][j] < 0) res.f[i][j] += m;
			}
		}
	}
	return res;
}
Matrix operator ^ (Matrix m, long long p) {
	if (p == 1) return m;
	else if (p == 2) return m * m;
	Matrix res = (m ^ (p / 2)) ^ 2;
	if (p % 2) res = res * m;
	return res;
}
int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &m, &a, &c, &x0, &n, &g), init();
	Ans = X * (B^n);
	long long a = Ans.f[0][0] % g;
	if (a < 0) a += g;
	printf("%lld\n", a);
}