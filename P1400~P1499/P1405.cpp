#include <cstdio>
#include <cstring>
#include <cmath>
char s[2500], tmp[2500], tmp1[2500];
long m, n, p;
inline void Print(char str[]) {
	for (long i = 0; i < strlen(str); i++) {
		for (long j = 1; j <= p + 1; j++) printf("%c", str[i]);
	}
}
inline void Replace(const char *src, const char *sch, const char *aim, char *des) {
	long pos1 = 0, pos2 = 0, len1 = strlen(src), len2 = strlen(sch), len3 = strlen(aim);
	while (strstr(src + pos1, sch) != NULL) {
		for (long i = pos1; i < len1 - strlen(strstr(src + pos1, sch)); i++) des[pos2++] = src[i];
		for (long i = 0; i < len3; i++) des[pos2++] = aim[i];
		pos1 = len1 - strlen(strstr(src + pos1, sch)) + len2;
	}
	for (long i = pos1; i < len1; i++) des[pos2++] = src[i];
}
int main() {
	scanf("%s", s), scanf("%ld%ld%ld", &m, &n, &p);
	if (n == 1) {
		for (long i = 0; i < strlen(s); i++) {
			if ((s[i] >= 'A') && (s[i] <= 'Z')) tmp[i] = s[i] - 'A' + 'a';
			else if ((s[i] >= 'a') && (s[i] <= 'z')) tmp[i] = s[i] - 'a' + 'A';
			else tmp[i] = s[i];
		}
		Print(strcat(tmp, "Immorta1"));
	}
	else if (n == 2) {
		Replace(s, s + m - 1, "", tmp);
		Replace(tmp, "1013", "hh4742", tmp1);
		Print(tmp1);
	}
	else if (n == 3) {
		if (m == 1) Print(s);
		else {
			for (long i = 0; i < (long)fabs(n - m) - 1; i++) tmp[i] = s[i];
			for (long i = m - 1; i < strlen(s); i++) tmp[(long)fabs(n - m) - 1 + (i - m + 1)] = s[i];
			for (long i = (long)fabs(n - m) - 1; i < m - 1; i++) tmp[strlen(s) + (i - m + 1)] = s[i];
			Print(tmp);
		}
	}
}