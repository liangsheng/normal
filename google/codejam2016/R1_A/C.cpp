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
#include <cfloat>
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

const int N = 1005;

int T, n;
int f[N], h[N], dp[N], ok[N];
vi g;

int main() {
    file_r("C-large-practice.in");
    file_w("c-large.out");
    int cas = 0, ans, flag, p, sz, tmp;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR (i, 1, n) scanf("%d", &f[i]);
        FOR (i, 1, n) dp[i] = 1;
        memset(ok, 0, sizeof(ok));
        ans = 0;
        FOR (i, 1, n) {
            //sc(i);
            memset(h, 0, sizeof(h));
            p = i, flag = 1, h[i] = 1;
            g.clear(), g.pb(i);
            while (f[p] != g[0] && f[p] != g[SZ(g) - 2]) {
                p = f[p];
                if (h[p]) {
                    flag = 0;
                    break;
                }
                //sc(p);
                h[p] = 1;
                g.pb(p);
            }
            //sc(flag);
            if (!flag) continue;
            sz = SZ(g);
            if (f[p] == g[0] && sz > 2) ans = max(ans, sz);
            else {
                rep (j, sz - 1) dp[g[j]] = max(dp[g[j]], j + 1);
                ok[g[sz - 2]] = 1, ok[g[sz - 1]] = 1;
                //sc2(g[sz - 2], g[sz - 1]);
            }
        }
        //FOR (i, 1, n) sc2(i, dp[i]);
        tmp = 0;
        FOR (i, 1, n) if (ok[i]) tmp += dp[i];
        //sc2(ans, tmp);
        ans = max(ans, tmp);
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}


