#include <cstdio>
long n, tmp, tb1, tb2, b[1505];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &tb1), b[i] = tb1 - tb2, tb2 = tb1, tmp = i;
		while (!b[tmp]) tmp--;
		printf("%ld ", i - tmp + 1);
		b[tmp]--;
	}
}
/*
˼·������������ջģ������������к���Ů������Ϊ1��n�ţ���i��Ů����ߵ��к���a[i]����
��i��Ů������������ڸ�Ů������ߣ�����a[i]=�к��ı�ţ�
������һ�����֮������ֻ��k(k=0, 1, ...)����飬��û�����䵥��
�����i��Ů����������Ů��֮����k����飬�����������֮����к���k����
�Ӷ���a[i]=�к��ı��+k. ��Ӧ�ģ�������ľ���Ϊ(k+1)=a[i]-�к��ı��+1.
���ǿ�����Ԫ��1��n��ջ����ջ�Ĺ���Ϊ��
��i��Ů������(topԪ�ر��+1)��a[i]��Ԫ��ȫ����ջ������δ���룩��
�ر�ģ���ջΪ�գ����ջԪ��Ϊ1��a[i]��
Ȼ��topԪ��ȡ������������ľ���Ϊa[i]-topԪ�ر��+1.
*/

/*
ջ��д�����Ըĳ����Ա���д����Ҳ����b[i]Ϊi��Ů����(i-1)��Ů������ģ���δƥ��ģ��к�������
��ǰ��֪����ʼʱb[i]����i��Ů����(i-1)��Ů�������������
��b[i]��Ϊ�㣬��i��Ů�����ڽ����к�ֱ����ԣ���ʱb[i]��һ��
�������i��Ů����(i-1)��Ů��֮��û�У���δƥ��ģ��к�������ǰ��֪���֮�����û���䵥��
��(i-1)��Ů���Ѿ�ƥ�䣬��ʱ������Ѱʹb[i]��Ϊ���iֵ����(iʼ-iĩ)��Ϊ������������������
��������ľ��뼴Ϊ(iʼ-iĩ+1).
*/