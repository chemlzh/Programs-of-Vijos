#include <cstdio>
#include <string>
using namespace std;
string tmp, name;
char cow[1005];
long n,now,ans;
inline long stat(string s,string t) {
	long cnt=0,pos = t.find(s);
	while (pos != -1) { cnt++; pos = t.find(s, pos + s.size()); }
	return cnt;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%s", cow); tmp = cow;
		if (tmp.find("reioxzsj") != -1) {
			long pos = tmp.find("woc");
			while (pos!=-1) {
				tmp.replace(pos,3 ,"drib" );
				pos = tmp.find("woc",pos+3);
			}
			now = 5 * stat("r",tmp)+5*stat("p",tmp)+20*stat("pr",tmp);
			if ((now > ans)|| (now == ans&&tmp.size() < name.size())) {
				ans = now; name = cow;
			}
		}
	}
	printf("%s\n", name.c_str()); printf("%ld\n", ans);
}