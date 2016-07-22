/* **********************************************
 Author      : kuangbin
 Created Time: 2013/8/12 21:58:47
 File Name   : F:\2013ACM��ϰ\ר��ѧϰ\�����ʷ�\����ͳ��Count.cpp
 *********************************************** */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

typedef long long LL;

const int MAXN = 500005, MOD = 1000000007;
struct Edge {
	int to, next;
} edge[MAXN * 2];
int head[MAXN], tot;
int top[MAXN]; //top[v] ��ʾv���ڵ������Ķ��˽ڵ�
int fa[MAXN]; //���׽ڵ�
int deep[MAXN]; //���
int num[MAXN]; //num[v]��ʾ��vΪ���������Ľڵ���
int p[MAXN]; //p[v]��ʾv���߶����е�λ��
int fp[MAXN]; //��p�����෴
int son[MAXN]; //�ض���
int pos;
void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
	pos = 0;
	memset(son, -1, sizeof(son));
}
void addedge(int u, int v) {
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void dfs1(int u, int pre, int d) { //��һ��dfs���fa,deep,num,son
	deep[u] = d;
	fa[u] = pre;
	num[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if (v != pre) {
			dfs1(v, u, d + 1);
			num[u] += num[v];
			if (son[u] == -1 || num[v] > num[son[u]])
				son[u] = v;
		}
	}
}
void getpos(int u, int sp) {
	top[u] = sp;
	p[u] = pos++;
	fp[p[u]] = u;
	if (son[u] == -1)
		return;
	getpos(son[u], sp);
	for (int i = head[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if (v != son[u] && v != fa[u])
			getpos(v, v);
	}
}

struct Node {
	int l, r;
	int mul;
} segTree[MAXN * 4];
void push_up(int i) {
	segTree[i].mul = (LL) segTree[i << 1].mul * segTree[(i << 1) | 1].mul % MOD;
}
int s[MAXN];
void build(int i, int l, int r) {
	segTree[i].l = l;
	segTree[i].r = r;
	if (l == r) {
		segTree[i].mul = s[fp[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(i << 1, l, mid);
	build((i << 1) | 1, mid + 1, r);
	push_up(i);
}
void update(int i, int k, int val) { //�����߶����ĵ�k��ֵΪval
	if (segTree[i].l == k && segTree[i].r == k) {
		segTree[i].mul = val;
		return;
	}
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (k <= mid)
		update(i << 1, k, val);
	else
		update((i << 1) | 1, k, val);
	push_up(i);
}
int queryMul(int i, int l, int r) { //��ѯ�߶���[l,r]����ĳ˻�
	if (segTree[i].l == l && segTree[i].r == r)
		return segTree[i].mul;
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (r <= mid)
		return queryMul(i << 1, l, r);
	else if (l > mid)
		return queryMul((i << 1) | 1, l, r);
	else
		return (LL) queryMul(i << 1, l, mid) * queryMul((i << 1) | 1, mid + 1, r) % MOD;
}
int findMul(int u, int v) { //��ѯu->v·���Ͻڵ��Ȩֵ�ĺ�
	int f1 = top[u], f2 = top[v];
	int tmp = 1;
	while (f1 != f2) {
		if (deep[f1] < deep[f2]) {
			swap(f1, f2);
			swap(u, v);
		}
		tmp = (LL) tmp * queryMul(1, p[f1], p[u]) % MOD;
		u = fa[f1];
		f1 = top[u];
	}
	if (deep[u] > deep[v])
		swap(u, v);
	return (LL) tmp * queryMul(1, p[u], p[v]) % MOD;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	int q;
	int d, u, v;
	while (scanf("%d", &n) == 1) {
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", &s[i]);
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		dfs1(1, 0, 0);
		getpos(1, 1);
		build(1, 0, pos - 1);
		scanf("%d", &q);
		while (q--) {
			scanf("%d %d %d", &d, &u, &v);
			if (d == 0) printf("%d\n", findMul(u, v));
			else update(1, p[u], v);

//			if (op[0] == 'C')
//				update(1, p[u], v);    //�޸ĵ����ֵ
//			else if (strcmp(op, "QMAX") == 0)
//				printf("%d\n", findMax(u, v));    //��ѯu->v·���ϵ�Ȩ�����ֵ
//			else
//				printf("%d\n", findSum(u, v));    //��ѯ·���ϵ�Ȩ�ĺ�
		}
	}
	return 0;
}
