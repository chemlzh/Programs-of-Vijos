#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
using namespace std;
struct letter { string element; long status; };
stack<letter> l;
char s[1005],ans[1005];
long len;

inline string transform(){
	letter a, b, temp;
	for (long i = 0; i < len; i++) {
		if ((s[i] >= 'A') && (s[i] <= 'Z')) { 
			temp.element += s[i]; temp.status = 0;  
			l.push(temp); temp.element = "";
		}
		else if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/')) {
			b = l.top(); l.pop(); a = l.top(); l.pop();
			if (s[i] == '+') {
				temp.element = a.element + s[i] + b.element; temp.status = 1; 
				l.push(temp); temp.element = "";
			}
			if (s[i] == '-') {
				if (b.status == 1) b.element = "(" + b.element + ")";
				temp.element = a.element + s[i] + b.element; temp.status = 1; 
				l.push(temp); temp.element = "";
			}
			if (s[i] == '*') {
				if (b.status == 1) b.element = "(" + b.element + ")";
				if (a.status == 1) a.element = "(" + a.element + ")";
				temp.element = a.element + s[i] + b.element; temp.status = 2; 
				l.push(temp); temp.element = "";
			}
			if (s[i] == '/') {
				if (b.status!=0) b.element = "(" + b.element + ")";
				if (a.status == 1) a.element = "(" + a.element + ")";
				temp.element = a.element + s[i] + b.element; temp.status = 2; 
				l.push(temp); temp.element = "";
			}
		}
	}
	return l.top().element;
}

int main() {
	scanf("%s", s); len = strlen(s);
	printf("%s\n", transform().c_str());
}