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
#define sqr(r) ((r) * (r))
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

const int N = 1005, M = N * 30, CH = 2, S = 30;

int T, n, e;
int a[N];
int chd[M][CH], f[M][3];
int b[S + 5];

void init() {
    e = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    f[0][0] = 0, f[0][1] = f[0][2] = -1;
}

void hl(int p, int id) {
    f[p][0]++;
    if (f[p][1] == -1) f[p][1] = id;
    else if (f[p][2] == -1) f[p][2] = id;
}

void gao(int x) {
    memset(b, 0, sizeof(b));
    if (x == 0) b[0] = 0, sz = 1;
    else {
        sz = 0;
        while (x != 0) {
            b[sz++] = x & 1;
            x >>= 1;
        }
    }
}

void add(int x, int id) {
    int p = 0;
    gao(x);
    hl(p, id);
    FORD (i, S - 1, 0) {
        if (chd[p][b[i]] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            f[e][0] = 0, f[e][1] = f[e][2] = -1;
            e++;
        }
        p = chd[p][a[i]];
        hl(p, id);
    }
}

int work(int x, int i, int j) {
    int p = 0;
    gao(x);

}

int main() {
    //cout << (1LL << 30) << '\n' << 1000000000 << '\n' << (~0U >> 1);
    int ans, tmp, res;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        rep (i, n) {
            scanf("%d", &a[i]);
            add(a[i], i);
        }
        ans = -1;
        rep (i, n) FORD (j, i + 1, n - 1) {
            tmp = a[i] + a[j];
            res = work(tmp, i, j);
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
























