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

#define sc(x) cout << #x" = " << x << endl
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl

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

const int N = 200005;

int n, m;
pair<int, pii> a[N];
vi ans;

bool check(int num) {
	int tol = 0, sz;
	vpii all;
	rep (i, n) if (a[i].X >= num) all.pb(a[i].Y);
	sort(ALL(all));
	ans.clear();
	sz = SZ(all);
	if (sz < num) return 0;
	rep (i, num) tol += all[i].X, ans.pb(all[i].Y);
	return tol <= m;
}

int main() {
	int l, r, mid;
	while (~in2(n, m)) {
		rep (i, n) {
			in2(a[i].X, a[i].Y.X);
			a[i].Y.Y = i + 1;
		}
		sort(a, a + n);
		l = 0, r = n;
		while (l != r) {
			mid = (l + r) / 2 + 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}
		check(l);
		printf("%d\n%d\n", l, l);
		rep (i, l) printf("%d%c", ans[i], i == l - 1 ? '\n': ' ');
	}
	return 0;
}