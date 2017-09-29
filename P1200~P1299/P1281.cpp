#include <cstdio>
long k, n, flag, tmp;
int main() {
	scanf("%ld", &k);
	for (long i = 1; i <= k; i++) {
		scanf("%ld", &n);	scanf("%ld", &flag);
		for (long j = 1; j <= n; j++) scanf("%ld",&tmp);
		if (flag) printf("%s\n", "lolanv"); else printf("%s\n", "wind");
	}
}

/*
这道题的题型是博弈论，因此有必要讨论先手必赢的可能性。
因为每一次取数时，要么取奇数项的数，要么取偶数项的数。所以先手将有两个选择：第一次取奇数项，或取偶数项。
若取奇（偶）数项，则由于游戏用的数个数为偶数，故先手第一次取后，后手只能取偶（奇）数项。
接下来又回到了先手选择取奇数项或取偶数项的局面。
因此，先手可以计算取全部奇数项及取全部偶数项的总和，若奇（偶）数项和更大，则先手就一直取奇（偶）数项，从而保持胜局。
*/