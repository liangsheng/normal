// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheEmpireStrikesBack.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
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

const int N = 100005, INF = ~0U >> 1;

bool f[N];
pii p[N], a[N];

class TheEmpireStrikesBack {
public:
    int find(int AX, int BX, int CX, int AY, int BY, int CY, int n, int m) {
        int l = 0, r = -INF, mid, e = 0, cnt, id, t;
        p[0].X = AX, r = max(r, p[0].X);
        FOR (i, 1, n - 1) {
            p[i].X = ((LL) p[i - 1].X * BX + CX) % 1000000007;
            r = max(r, p[i].X);
        }

        p[0].Y = AY, r = max(r, p[0].Y);
        FOR (i, 1, n - 1) {
            p[i].Y = ((LL) p[i - 1].Y * BY + CY) % 1000000007;
            r = max(r, p[i].Y);
        }
        sort(p, p + n);
        FORD (i, n - 1, 0) {
            if (i == n - 1) a[e++] = p[i];
            else {
                if (p[i].X == p[i - 1].X || p[i].Y <= a[e - 1].Y) continue;
                a[e++] = p[i];
            }
        }
        //rep (i, e) sc2(a[i].X, a[i].Y);
        //sc2(l, r);
        while (l != r) {
            mid = (l + r) >> 1, cnt = 0, id = 0;
            memset(f, 0, sizeof(f));
            rep (i, e) {
                id = i, f[id] = 1, cnt++;
                while (id + 1 < e && a[i].X - a[id + 1].X <= mid) id++, f[id] = 1;
                t = id;
                while (t + 1 < e && a[t + 1].Y - a[id].Y <= mid) t++, f[t] = 1;
                i = t;
            }
            //sc4(l, r, mid, cnt);
            if (cnt <= m) r = mid;
            else l = mid + 1;
        }
        //sc2(e, l);
        return l;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; int Arg6 = 2; int Arg7 = 1; int Arg8 = 0; verify_case(0, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 1000000000; int Arg6 = 2; int Arg7 = 1; int Arg8 = 1; verify_case(1, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 8; int Arg3 = 10000; int Arg4 = 10; int Arg5 = 999910000; int Arg6 = 3; int Arg7 = 1; int Arg8 = 30; verify_case(2, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 100000; int Arg7 = 1000; int Arg8 = 0; verify_case(3, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 30; int Arg3 = 40; int Arg4 = 50; int Arg5 = 60; int Arg6 = 100000; int Arg7 = 10; int Arg8 = 15720; verify_case(4, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
        TheEmpireStrikesBack ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
