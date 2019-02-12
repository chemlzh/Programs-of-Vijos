#include <cstdio>
long n, m, t[105];
long long f[105][105], ans = 0;
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= n; i++) scanf("%ld", &t[i]), f[1][i] = 1;
	for (long i = 2; i <= m; i++) {
		for (long j = i; j <= n; j++) {
			for (long k = i - 1; k <= j - 1; k++) {
				if (t[j] > t[k]) f[i][j] += f[i - 1][k];
			}
		}
	}
	for (long i = 1; i <= n; i++) ans += f[m][i];
	printf("%I64d\n", ans);
}
/*
��f[i][j]Ϊ����Ϊi������t[j]��β�Ĳ��½���������������
f[i][j]=sum(f[i-1][k]) (k=i-1..j-1, j=i..n, i=2..m, if t[k]<t[j])
�߽�����f[1][j]=1 (j=1..n)
���Ϊans=sum(f[m][j]) (j=1..n)
*/