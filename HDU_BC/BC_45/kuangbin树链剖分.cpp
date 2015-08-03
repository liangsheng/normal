/* **********************************************
 Author      : kuangbin
 Created Time: 2013/8/12 21:58:47
 File Name   : F:\2013ACM练习\专题学习\数链剖分\树的统计Count.cpp
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

const int MAXN = 30010;
struct Edge {
	int to, next;
} edge[MAXN * 2];
int head[MAXN], tot;
int top[MAXN]; //top[v] 表示v所在的重链的顶端节点
int fa[MAXN]; //父亲节点
int deep[MAXN]; //深度
int num[MAXN]; //num[v]表示以v为根的子树的节点数
int p[MAXN]; //p[v]表示v在线段树中的位置
int fp[MAXN]; //和p数组相反
int son[MAXN]; //重儿子
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
void dfs1(int u, int pre, int d) { //第一遍dfs求出fa,deep,num,son
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
	int sum;
	int Max;
} segTree[MAXN * 3];
void push_up(int i) {
	segTree[i].sum = segTree[i << 1].sum + segTree[(i << 1) | 1].sum;
	segTree[i].Max = max(segTree[i << 1].Max, segTree[(i << 1) | 1].Max);
}
int s[MAXN];
void build(int i, int l, int r) {
	segTree[i].l = l;
	segTree[i].r = r;
	if (l == r) {
		segTree[i].sum = segTree[i].Max = s[fp[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(i << 1, l, mid);
	build((i << 1) | 1, mid + 1, r);
	push_up(i);
}
void update(int i, int k, int val) { //更新线段树的第k个值为val
	if (segTree[i].l == k && segTree[i].r == k) {
		segTree[i].sum = segTree[i].Max = val;
		return;
	}
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (k <= mid)
		update(i << 1, k, val);
	else
		update((i << 1) | 1, k, val);
	push_up(i);
}
int queryMax(int i, int l, int r) { //查询线段树[l,r]区间的最大值
	if (segTree[i].l == l && segTree[i].r == r) {
		return segTree[i].Max;
	}
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (r <= mid)
		return queryMax(i << 1, l, r);
	else if (l > mid)
		return queryMax((i << 1) | 1, l, r);
	else
		return max(queryMax(i << 1, l, mid), queryMax((i << 1) | 1, mid + 1, r));
}
int querySum(int i, int l, int r) { //查询线段树[l,r]区间的和
	if (segTree[i].l == l && segTree[i].r == r)
		return segTree[i].sum;
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (r <= mid)
		return querySum(i << 1, l, r);
	else if (l > mid)
		return querySum((i << 1) | 1, l, r);
	else
		return querySum(i << 1, l, mid) + querySum((i << 1) | 1, mid + 1, r);
}
int findMax(int u, int v) { //查询u->v路径上节点的最大权值
	int f1 = top[u], f2 = top[v];
	int tmp = -1000000000;
	while (f1 != f2) {
		if (deep[f1] < deep[f2]) {
			swap(f1, f2);
			swap(u, v);
		}
		tmp = max(tmp, queryMax(1, p[f1], p[u]));
		u = fa[f1];
		f1 = top[u];
	}
	if (deep[u] > deep[v])
		swap(u, v);
	return max(tmp, queryMax(1, p[u], p[v]));
}
int findSum(int u, int v) { //查询u->v路径上节点的权值的和
	int f1 = top[u], f2 = top[v];
	int tmp = 0;
	while (f1 != f2) {
		if (deep[f1] < deep[f2]) {
			swap(f1, f2);
			swap(u, v);
		}
		tmp += querySum(1, p[f1], p[u]);
		u = fa[f1];
		f1 = top[u];
	}
	if (deep[u] > deep[v])
		swap(u, v);
	return tmp + querySum(1, p[u], p[v]);
}
int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	int q;
	char op[20];
	int u, v;
	while (scanf("%d", &n) == 1) {
		init();
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &s[i]);
		dfs1(1, 0, 0);
		getpos(1, 1);
		build(1, 0, pos - 1);
		scanf("%d", &q);
		while (q--) {
			scanf("%s%d%d", op, &u, &v);
			if (op[0] == 'C')
				update(1, p[u], v);    //修改单点的值
			else if (strcmp(op, "QMAX") == 0)
				printf("%d\n", findMax(u, v));    //查询u->v路径上点权的最大值
			else
				printf("%d\n", findSum(u, v));    //查询路径上点权的和
		}
	}
	return 0;
}
