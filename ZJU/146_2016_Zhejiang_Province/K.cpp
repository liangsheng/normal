#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define ins insert
#define rb rbegin
#define be begin
#define er erase
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((LL) (r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 100005, M = N * 2;

int n, m, e;
int head[N], pnt[M], nxt[M], c[M], t[M];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int tim, int cst) {
    pnt[e] = v, t[e] = tim, c[e] = cst;
    nxt[e] = head[u], head[u] = e++;
}

LL dis[N];
bool vis[N];
queue<int> q;

int T;
LL rest, resc;

void spfa() {
    int u, v;
    LL tmp;
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[0] = 0, vis[0] = 1, q.push(0);
    while (!q.empty()) {
        u = q.front(), q.pop(), vis[u] = 0;
        repe (i, u) {
            v = pnt[i];
            tmp = dis[u] + t[i];
            if (dis[v] == -1 || dis[v] > tmp) {
                dis[v] = tmp;
                if (!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
    rest = 0;
    rep (i, n) rest += dis[i];
}

int a[N];

void gao() {
    int v;
    memset(a, 127, sizeof(a));
    FOR (u, 1, n - 1) repe (i, u) {
        v = pnt[i];
        if (dis[v] + t[i] == dis[u]) a[u] = min(a[u], c[i]);
    }
    resc = 0;
    FOR (i, 1, n - 1) resc += a[i];
}

int main() {
    int u, v, tim, cst;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &n, &m);
        rep (i, m) {
            scanf("%d %d %d %d", &u, &v, &tim, &cst);
            add_edge(u, v, tim, cst);
            add_edge(v, u, tim, cst);
        }
        spfa();
        gao();
        printf("%lld %lld\n", rest, resc);
    }
    return 0;
}
















