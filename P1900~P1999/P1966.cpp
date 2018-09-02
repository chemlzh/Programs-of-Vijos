#include <cstdio>
#include <cstring>
#include <cmath>
long n, m, u, v, w, map[205][205];
double f[205][205];
inline void swap(long r1, long r2) {
	double t[205];
	memcpy(t, f[r1], sizeof(f[r1]));
	memcpy(f[r1], f[r2], sizeof(f[r2]));
	memcpy(f[r2], t, sizeof(t));
}
inline void gauss() {		// Gauss elimination.
	long tmp;
	double d;
	for (long i = 1; i <= n; i++) {			// Find a row with the maximum of abs(f[j][i]).
		tmp = i;
		for (long j = i + 1; j <= n; j++) {
			if (fabs(f[tmp][i]) < fabs(f[j][i])) tmp = j;
		}
		if (tmp != i) swap(tmp, i);			// Swap the row.
		for (long j = i + 1; j <= n; j++) {	// Transform into upper triangular matrix.
			d = f[j][i] / f[i][i];
			for (long k = i; k <= n + 1; k++) f[j][k] -= f[i][k] * d;
		}
	}
	for (long i = n; i >= 1; i--) {		// Reduction.
		for (long j = i + 1; j <= n; j++) f[i][n + 1] -= f[i][j] * f[j][n + 1];
		f[i][n + 1] /= f[i][i];
	}
}
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= m; i++) {
		scanf("%ld%ld%ld", &u, &v, &w);
		map[u][v] = map[v][u] = w;
	}
	f[n][n] = 1;
	for (long i = 1; i < n; i++) {
		long cnt = 0;
		for (long j = 1; j <= n; j++) {
			if (map[i][j]) f[i][j] = -1, f[i][n+1] += map[i][j], cnt++;
		}
		f[i][i] = cnt;
	}
	gauss();
	printf("%.1f\n", f[1][n + 1] + 1e-5);		// Awful precision!
}

/*
This question is related to Markov process, therefore we'd better find functions to solve it.
Suppose f(x) is the mean time of reaching place n from place x (x is between 1 and n).
Then we can find a function: f(x) = (f(x1) + d(x¡úx1)) / c + (f(x2) + d(x¡úx2)) / c + ¡­ + (f(xc) + d(x¡úxc)) / c,
where x1, x2, ¡­ , xc are connected with x, and c is the number of places which are connected to x.
Specially, f(n) = 0, since the main character will stop if he or she reaches place n.
Using Gauss elimination, we can solve these functions, and it's done!
*/