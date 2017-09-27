#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
double a, b, c, d, ans[5];

inline double work(double s) {								//the tangent's function
	return s - (a*s*s*s+b*s*s+c*s+d) / (3*a*s*s+2*b*s+c);
}

inline double newton(double s) {							//Newton's method
	double x0 = s, x=work(x0);
	while (abs(x - x0) > 0.0001){
		x0 = x; x = work(x0);
	}
	return x;
}

int main() {
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	ans[0] = newton(-100.0); ans[1] = newton(100.0); ans[2] = -d / ans[0] / ans[1]; sort(ans, ans + 3);			//Vieta's forlumas
	printf("%.2f %.2f %.2f\n",ans[0],ans[1],ans[2]);
}