#include <cstdio>
#include <cmath>
const long SelNum[6] = { 1,2,3,5,7,9 };
long n;
inline bool judge(long num) {
	for (long i = 2; i <= (long)sqrt(num); i++) {
		if (!(num%i)) return false;
	}
	return true;
}
inline void dfs(long depth,long num) {
	if (depth > n) {
		printf("%ld\n", num);
	}
	else if (depth==1){
		for (long i = 1; i <= 4; i++) dfs(depth + 1, num * 10 + SelNum[i]);
	}
	else {
		for (long i = 0; i <= 5; i++) {
			if (judge(num*10+SelNum[i])) dfs(depth + 1, num * 10 + SelNum[i]);
		}
	}
}
int main() {
	scanf("%ld", &n);
	dfs(1, 0);
}