#include <algorithm>
#include <cstdio>
using namespace std;
long n, k, cnt, score[100005];
int main() {
	scanf("%ld%ld", &n, &k);
	for (long i = 1; i <= n; i++) scanf("%ld", &score[i]);
	sort(score+1,score+n+1);
	printf("%ld\n",score[n-k+1]);
}