/* **********************************************
Author      : kuangbin
Created Time: 2013/8/12 21:58:47
File Name   : F:\2013ACM��ϰ\ר��ѧϰ\�����ʷ�\����ͳ��Count.cpp
*********************************************** */
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int MAXN = 100010;
struct Edge {
    int to,next;
} edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN]; //top[v] ��ʾv���ڵ������Ķ��˽ڵ�
int fa[MAXN]; //���׽ڵ�
int deep[MAXN];//���
int num[MAXN]; //num[v]��ʾ��vΪ���������Ľڵ���
int p[MAXN]; //p[v]��ʾv���߶����е�λ��
int fp[MAXN];//��p�����෴
int son[MAXN];//�ض���
int pos;
void init() {
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 0;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs1(int u,int pre,int d) { //��һ��dfs���fa,deep,num,son
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(v != pre) {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}
void getpos(int u,int sp) {
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son[u] == -1) return;
    getpos(son[u],sp);
    for(int i = head[u]; i != -1 ; i = edge[i].next) {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u]) getpos(v,v);
    }
}

struct Node {
    int l,r;
    int sum, yh, c0;
    int Max;
} segTree[MAXN*3];
void push_up(int i) {
    segTree[i].sum = segTree[i<<1].sum + segTree[(i<<1)|1].sum;
    segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
    segTree[i].yh = segTree[i<<1].yh ^ segTree[(i<<1)|1].yh;
    segTree[i].c0 = segTree[i<<1].c0 + segTree[(i<<1)|1].c0;
}
int s[MAXN];
void build(int i,int l,int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    if(l == r) {
        segTree[i].sum = segTree[i].Max = segTree[i].yh = s[fp[l]];
        segTree[i].c0 = (s[fp[l]] == 0);
        return ;
    }
    int mid = (l + r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    push_up(i);
}
void update(int i,int k,int val) { //�����߶����ĵ�k��ֵΪval
    if(segTree[i].l == k && segTree[i].r == k) {
        segTree[i].sum = segTree[i].Max = segTree[i].yh = val;
        segTree[i].c0 = (val == 0);
        return;
    }
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(k <= mid)update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}

int queryMax(int i,int l,int r) { //��ѯ�߶���[l,r]��������ֵ
    if(segTree[i].l == l && segTree[i].r == r) {
        return segTree[i].Max;
    }
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid) return queryMax(i<<1,l,r);
    else if(l > mid)return queryMax((i<<1)|1,l,r);
    else return max(queryMax(i<<1,l,mid),queryMax((i<<1)|1,mid+1,r));
}

int querySum(int i,int l,int r) { //��ѯ�߶���[l,r]����ĺ�
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].sum;
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return querySum(i<<1,l,r);
    else if(l > mid)return querySum((i<<1)|1,l,r);
    else return querySum(i<<1,l,mid) + querySum((i<<1)|1,mid+1,r);
}

int queryC0(int i,int l,int r) { //��ѯ�߶���[l,r]�����0�ĸ���
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].c0;
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return queryC0(i<<1,l,r);
    else if(l > mid)return queryC0((i<<1)|1,l,r);
    else return queryC0(i<<1,l,mid) + queryC0((i<<1)|1,mid+1,r);
}

int queryXor(int i,int l,int r) { //��ѯ�߶���[l,r]����ĺ�
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].yh;
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return queryXor(i<<1,l,r);
    else if(l > mid)return queryXor((i<<1)|1,l,r);
    else return queryXor(i<<1,l,mid) ^ queryXor((i<<1)|1,mid+1,r);
}

int findMax(int u,int v) { //��ѯu->v·���Ͻڵ�����Ȩֵ
    int f1 = top[u] , f2 = top[v];
    int tmp = -1000000000;
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        tmp = max(tmp,queryMax(1,p[f1],p[u]));
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
    return max(tmp,queryMax(1,p[u],p[v]));
}
int findSum(int u,int v) { //��ѯu->v·���Ͻڵ��Ȩֵ�ĺ�
    int f1 = top[u], f2 = top[v];
    int tmp = 0;
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        tmp += querySum(1,p[f1],p[u]);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
    return tmp + querySum(1,p[u],p[v]);
}
int findC0(int u,int v) { //��ѯu->v·���Ͻڵ��Ȩֵ0�ĸ���
    int f1 = top[u], f2 = top[v];
    int tmp = 0;
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        tmp += queryC0(1,p[f1],p[u]);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
    return tmp + queryC0(1,p[u],p[v]);
}
int findXor(int u,int v) { //��ѯu->v·���Ͻڵ��Ȩֵ��xor
    int f1 = top[u], f2 = top[v];
    int tmp = 0;
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        tmp ^= queryXor(1,p[f1],p[u]);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
    return tmp ^ queryXor(1,p[u],p[v]);
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int q;
    int op;
    int u,v;
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &q);
        init();
        for(int i = 1; i < n; i++) {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        for(int i = 1; i <= n; i++)
            scanf("%d",&s[i]);
        //for (int i = 1; i <= n; i++) cout << i << ' ' << s[i] << '\n';
        dfs1(1,0,0);
        getpos(1,1);
        build(1,0,pos-1);
        //scanf("%d",&q);
        while(q--) {
            scanf("%d%d%d",&op,&u,&v);
            if(op == 0)
                update(1,p[u],v);//�޸ĵ����ֵ
//            else if(strcmp(op,"QMAX") == 0)
//                printf("%d\n",findMax(u,v));//��ѯu->v·���ϵ�Ȩ�����ֵ
//            else printf("%d\n",findSum(u,v));//��ѯ·���ϵ�Ȩ�ĺ�
            else if (op == 1) {
                int nn = findC0(u, v);
                if (nn % 2) printf("%d\n", 0);
                else {
                    int ans = findXor(u, v);
                    if (ans == 0) ans = -1;
                    printf("%d\n", ans);
                }
            }
        }
    }
    return 0;
}
/*
1
3 2
1 2
2 3
0 0 0
1 1 2
1 1 3
*/
