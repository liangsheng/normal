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

const int N = 1005;
const int NODE = 1005;
const int CH = 26;

int e;
int chd[NODE][CH];
int work[NODE];
int fail[NODE];
int q[NODE];

void init() {
    e = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    work[0] = 0;
}

void add(char* str, int val) {
    int i, id, p = 0;
    for (i = 0; str[i]; i++) {
        id = str[i] - '0';
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            work[e] = 0;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }
    work[p] = val;
}

void build() {
    int i, p, v, head, tail;
    fail[0] = head = tail = 0;
    for (i = 0; i < CH; i++) {
        if (chd[0][i] != -1) {
            fail[chd[0][i]] = 0;
            q[tail++] = chd[0][i];
        } else chd[0][i] = 0;
    }
    while (head != tail) {
        p = q[head++];
        for (i = 0; i < CH; i++) {
            v = chd[p][i];
            if (v != -1) {
                fail[v] = chd[fail[p]][i];
                if (work[fail[v]] == -1) work[v] = -1;
                q[tail++] = v;
            } else chd[p][i] = chd[fail[p]][i];
        }
    }
}

int main() {
    return 0;
}


























