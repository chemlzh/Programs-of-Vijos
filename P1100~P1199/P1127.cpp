#include <cstdio>
#include <cstring>
long n,k;
double d;
int main(){
	scanf("%ld",&k);
	for (long i=1;;i++){ d+=1/(double)i; if (d>k) { printf("%ld\n",i); break;} }
}
