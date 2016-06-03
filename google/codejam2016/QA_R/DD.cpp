#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
const int N = 1010, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int casenum, casei;
void fre()
{
	freopen("c://test//input.in", "r", stdin);
	freopen("c://test//output.out", "w", stdout);
}
LL k, c, s;
void solve()
{
	int p = 0;
	while (p < k)
	{
		LL pos = 0;
		for (int i = 0; i < c; ++i)
		{
			pos = pos*k + min((LL)p, k - 1);
			++p;
		}
		printf("%lld ", pos + 1);
	}puts("");
}
int main()
{
	//fre();
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		scanf("%lld%lld%lld", &k, &c, &s);
		printf("Case #%d: ", casei);
		if (s*c < k)puts("IMPOSSIBLE");
		else solve();
	}
}
/*
��trick&&�²ۡ�
�ֶ�ģ���ҹ�����ʵ�ǽ�������������֮��Ч�ķ�����

�����⡿
https://code.google.com/codejam/contest/6254486/dashboard#s=p3
����һ��K����ʾ���ǵĻ���ͼ�Σ���λ�ڸ��Ӷ�1�£���
ͼ�ΰ���'L'��'G'�����ַ���
�����ڸ��Ӷ�i�µ�ͼ�Σ�����仯Ϊ���Ӷ�i+1ͼ�ε�ʱ��
'L'���ɸ��Ӷ�Ϊ1�Ļ���ͼ��
'G'���Ϊ����ΪK��ȫ'G'ͼ��

�������ڵõ��˸��Ӷ�ΪC��ͼ�Ρ�Ȼ������֪�����ͼ����ʲô��
��������������ӵ��S�λ��ᣬ����֪�����Ӷ�ΪCͼ�ε����S��λ�õ�ͼ����ʲô��'L'����'G'��
�����ܷ�ѡ��S��λ�ã��жϳ�ԭʼͼ�����Ƿ���'G'����

1 �� T �� 100.
1 �� K �� 100.
1 �� C �� 100.
1<=S<=K
K^C �� 1018.
��С����S==K��

�����͡�
���� �ҹ���

��������
�����С������ȫ���ͷֵġ�
����С���ݣ����ǿ��Է��֣�ԭ����i��λ�ã�iΪ0base from 0~K-1)��
�ڸ��Ӷ�2�£����Ϊi*K+i
�ڸ��Ӷ�3�£����Ϊ(i*K+i)*K+i
����ֻҪ����ӳ����ȥ�����ֱ�Ӵ�����Ϳ����ҵ��𰸡�
Ȼ��������һ������ʵ����ֻҪ���ǰK��λ�þͿ����ˡ�
��Ϊ����Ҫ����ȫ��ΪG��Ҫ����Ϊ��һ�У�������������������Ƕ����Ի�ԭ�������С�

======================================================================
������Ҫ��δ���������أ�
��ʵ�ϡ���
K��Ϊԭ�����ȣ�C��Ϊԭ����չ�Ĵ�����SΪ���ǿ��Բ鿴��λ��
ֻҪK<=C*S����һ���н⡣

����˵��ԭ���ĳ���KΪ2���任�Ĵ���CΪ2���鿴��λ��SΪ1��
��Ϊyes������ֻҪ�鿴�ڶ���λ�þͿ����ˡ�

Ϊʲô�أ�
����KΪ2��ԭʼ����4��
LL��LG��GL��GG��
���Ǿ����任�����Ӧ��Ϊ����
LLLL��LGGG��GGGL��GGGG
��Ȼ������ֻҪ�鿴�ڶ���λ�þͿ��ԡ�

ԭʼ���ĳ���Խ�٣�������Ҫ�Ĳ鿴������Խ�٣�����ܺ���⡣
Ȼ�����任�Ĵ���Խ�࣬������Ҫ�鿴�Ĵ���ͬ��ҲԽ�٣������Ϊʲô�أ�

---------------------------------------------------------------------
���һ�εĴ�����Ϊn����i��λ�õ�Ϊa[i]

����һ�α任֮������ַ������Ϊn�Σ�ÿ�θ���n���ַ���
������ڵڶ�����ַ����ϲ�ѯ�����ǿ��Բ�ѯ��1���ַ��еĵ�2����
�������ַ���G����Ȼ�Ѿ�������
�������ַ�����G����Ȼ���ܹ�˵��a[1]!='G'��a[2]!='G'��һ������֤��2��λ��

�������α任֮������ַ������Ϊn*n*n�Ľṹ
����������ڵ�������ַ����ϲ�ѯ�����ǿ��Բ�ѯ��1����е�2С���еĵ�3���ַ���
�������ַ���G����Ȼ�Ѿ�������
�������ַ�����G����Ȼ����˵��a[1]!='G'��a[2]!='G'��a[3]!='G'

���ǡ���
C*S�����ǵ���֤������C*S>=K�𰸼�ΪPossible�����Ǽ����Ը���֮ǰ�ҵ��Ĺ��ɹ������ʵ�ַ�����
��ϸ���մ���

��ʱ�临�Ӷ�&&�Ż���
O(c+s+k)

*/
