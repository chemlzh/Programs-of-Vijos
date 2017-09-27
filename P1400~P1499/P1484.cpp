#include <cstdio>
char isbn[15];
long cnt,check;
int main() {
	scanf("%s", isbn);
	for (long i = 0; i <= 12; i++) {
		if (i == 12) {
			check %= 11;
			if ((check == 10 && isbn[i] == 'X') || check == isbn[i] - '0') printf("%s\n", "Right");
			else {
				if (check == 10) isbn[i] = 'X'; else isbn[i] = check + '0';
				printf("%s", isbn);
			}
		}
		else if (isbn[i] >= '0'&&isbn[i] <= '9') {
			cnt++; check += (isbn[i] - '0')*cnt;
		}
	}
}