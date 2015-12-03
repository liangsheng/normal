#include <bits/stdc++.h>

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

const int N = 100005;

int n;
char s[N];
int L[N][2], R[N][2];

int main() {
    int ans, tmp;
    while (~scanf("%d", &n)) {
        scanf("%s", s + 1);
        if (n == 1) {
            puts("1\n");
            continue;
        }
        L[0][0] = L[0][1] = 0;
        L[1][0] = (s[1] == '0'), L[1][1] = (s[1] == '1');
        FOR (i, 2, n) {
            L[i][0] = max(L[i - 1][0], s[i] == '0' ? L[i - 1][1] + 1 : 0);
            L[i][1] = max(L[i - 1][1], s[i] == '1' ? L[i - 1][0] + 1 : 0);
        }

        R[n + 1][0] = R[n + 1][1] = 0;
        R[n][0] = (s[n] == '0'), R[n][1] = (s[n] == '1');
        FORD (i, n - 1, 1) {
            R[i][0] = max(R[i + 1][0], s[i] == '0' ? R[i + 1][1] + 1 : 0);
            R[i][1] = max(R[i + 1][1], s[i] == '1' ? R[i + 1][0] + 1 : 0);
        }

        ans = max(L[n][0], L[n][1]);
        //sc(ans);
        FOR (i, 1, n) {
            tmp = max(L[i - 1][0] + R[i + 1][0] + 1, L[i - 1][1] + R[i + 1][1] + 1);
            //sc4(i, tmp, L[i - 1][0], R[i + 1][0]);
            ans = max(ans, tmp);
        }

        printf("%d\n", ans);
    }
    return 0;
}
