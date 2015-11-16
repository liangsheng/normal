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

const int N = 505;

int n;
int g[N][N];
vpii a[N];

int main() {
    int w, h, d, i, j, k, l, x, y, f;
    while (~scanf("%d", &n)) {
        if (n == 1) {
            puts("1 1\n1 1");
            continue;
        }
        for (i = 1; i <= n; i++) a[i].clear();
        if (n % 2)  h = (n + 1) / 2, w = n, d = (n - 1) / 2;
        else h = n / 2, w = n + 1, d = n / 2 + 1;
        //sc3(h, w, d);
        for (i = j = 1; i <= n; i += 2, j++) {
            for (k = 1; k <= (i + 1) / 2; k++) a[i].pb(mp(j, k)), g[j][k] = i;
            for (l = j - 1; l >= 1; l--) a[i].pb(mp(l, (i + 1) / 2)), g[l][(i + 1) / 2] = i;
        }
        x = 1, y = h + 1;
        //sc2(x, y);
        if (h % 2 == 0) {
            f = 1;
            for (i = 2; i <= n; i += 2) {
                for (j = 1; j <= i; j++) {
                    a[i].pb(mp(x, y));
                    g[x][y] = i;
                    x += f;
                    if (x > h) x = h, f = -1, y++;
                    else if (x < 1) x = 1, f = 1, y++;
                }
            }
        } else {
            //puts("DDDD");
            f = 1;
            for (i = 2; i <= n; i += 2) {
                for (j = 1; j <= i; j++) {
                    a[i].pb(mp(x, y));
                    g[x][y] = i;
                    y += f;
                    if (y > w) y = w, f = -1, x++;
                    else if (y < h + 1) y = h + 1, f = 1, x++;
                }
            }
        }
        printf("%d %d\n", h, w);
        for (i = 1; i <= n; i++) {
            for (j = 0; j < i - 1; j++) printf("%d %d ", a[i][j].X, a[i][j].Y);
            printf("%d %d\n", a[i][i - 1].X, a[i][i - 1].Y);
        }
        FOR (i, 1, h) {
            FOR (j, 1, w) cout << g[i][j];
            cout << '\n';
        }
    }
    return 0;
}
