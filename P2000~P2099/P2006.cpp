#include <algorithm>
#include <cstdio>
using namespace std;
long t, k, n, m, maxn, f[2001][2001], ans[2001][2001];
inline void ReadNum(long &num) {																				//读数过程
	char c = getchar(); num = 0;
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0'&&c <= '9') { num = num * 10 + c - '0'; c = getchar(); }
}
int main() {
	ReadNum(t); ReadNum(k);																						//要点1：用getchar()输入比用scanf()略快
	f[0][0] = 1;
	for (long a = 1; a <= t; a++) {
		ReadNum(n); ReadNum(m);
		for (long b = maxn + 1; b <= n; b++) {																//要点2：每次都从当前杨辉三角的下一行拓展
			f[b][0] = 1; 
			for (long c = 1; c <= b; c++) {
				f[b][c] = (f[b - 1][c] + f[b - 1][c - 1]) % k;														//要点3：计算时边加边取模，防止运算溢出
				if (c != b) ans[b][c] += ans[b - 1][c] + ans[b][c - 1] - ans[b - 1][c - 1];			//要点4：使用二维前缀和，加快运算速度
				else ans[b][c] = ans[b][c - 1];																		//要点5：ans[b][b]要特殊处理
				if (!f[b][c]) ans[b][c]++;																					//要点6：满足f[b][c]%k==0的ans[b][c]要加1
			}
		}
		maxn = max(n, maxn);																							//要点7：每次打表后要及时更新杨辉三角的最大行数
		if (m > n) printf("%ld\n", ans[n][n]); else printf("%ld\n", ans[n][m]);						//我就是因为忘记更新更新杨辉三角的最大行数而WA+TLE两遍，郁闷
	}
}

/*
描述
组合数C(m,n)表示的是从n个物品中选出m个物品的方案数。
举个例子，从(1, 2, 3)三个物品中选择两个物品可以有(1, 2), (1, 3), (2, 3)这三种选择方法。
根据组合数的定义，我们可以给出计算组合数的一般公式：C(m,n)=n!/(m!(n-m)!)，其中 n! = 1 x 2 x ... x n。
小葱想知道如果给定n, m和k，对于所有的0 <= i <= n, 0 <= j <= min(i, m)有多少对(i, j)满足C(i,j)是k的倍数。

题解
计算组合数可以用递推的方法，即推算出杨辉三角。
题目要求出有多少对(i, j)满足C(i,j)是k的倍数，即求杨辉三角中，在数组[0..n][0..min(i,m)]的范围内符合C(i,j)%k==0的个数，
因此我们可以用二维前缀和加快速度，即用ans[b][c]存储在数组[0..b][0..c]的范围内符合C(i,j)%k==0的个数，
其中ans[b][c] == ans[b][c] + ans[b - 1][c] + ans[b][c - 1] - ans[b - 1][c - 1]，
不过要注意ans[b][b]要特殊处理，即ans[b][b]=ans[b][b-1]，因b<c时无相应的前缀和，且f[b][b]=1,f[b][b]%k==1(k>=2)。
注意每次更新杨辉三角后要更新相应的最大行数，否则会导致程序从头算而算错或超时。
*/