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

const int N = 100005;

int n;
int a[N];
LL L[N], R[N];
set< pair<LL, int> > s;
set< pair<LL, int> > :: iterator top;

int main() {
    LL ans, hl, hr;
    while (~scanf("%d", &n)) {
        FOR (i, 1, n) scanf("%d", &a[i]);

        L[1] = a[1], ans = L[1];
        FOR (i, 2, n) {
            L[i] = a[i];
            if (L[i - 1] > 0) L[i] += L[i - 1];
            if (i != n) ans = max(ans, L[i]);
        }
        R[n] = a[n];
        FORD (i, n - 1, 1) {
            R[i] = a[i];
            if (R[i + 1] > 0) R[i] += R[i + 1];
            if (i != 1) ans = max(ans, R[i]);
        }
        //FOR (i, 1, n) cout << L[i] << ' '; puts("");
        //FOR (i, 1, n) cout << R[i] << ' '; puts("");
        //sc(ans);
        s.clear();
        FOR (i, 2, n) s.insert(mp(-R[i], i));
        FOR (i, 2, n - 1) {
            s.erase(mp(-R[i], i));
            top = s.begin();
            //sc2(i, top->X);
            ans = max(ans, L[i - 1] - top->X);
        }
        printf("%lld\n", ans);
    }
    return 0;
}




