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

const int N = 25;

int n, tol, ans, flag, id, d;
int b[N];
vi c;

struct VampireTree {
    int maxDistance(vector <int> a) {
        n = a.size(), tol = 0, ans = 0;
        rep (i, n) tol += a[i];
        if (tol != 2 * (n - 1)) return -1;
        memset(b, 0, sizeof(b));
        while (1) {
            c.clear(), tol = 0;
            rep (i, n) {
                tol += a[i];
                if (a[i] == 1) c.pb(i), a[i] = 0;
            }
            if (c.size() == 0) break;
            if (c.size() == 2 && tol == 2) {
                ans = max(b[c[0]] + b[c[1]] + 1, ans);
                break;
            }
            repit (it, c) {
                id = *it, d = -1;
                rep (i, n) if (d == -1 || a[i] > a[d]) d = i;
                //sc2(id, d);
                ans = max(ans, b[d] + b[id] + 1);
                b[d] = max(b[d], b[id] + 1);
                a[d]--;
            }
        }
        return ans;
    }
};

int main() {
    VampireTree p;
    vector<int> a = {1, 1, 1, 2, 3};
    cout << p.maxDistance(a) << '\n';
    return 0;
}



















