// BEGIN CUT HERE

// END CUT HERE
#line 5 "BracketSequenceDiv1.cpp"
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

const int N = 45;

int n;
LL dp[N][N];
int a[N];

class BracketSequenceDiv1 {
        public:
        long long count(string s) {
            int l, r;
            LL x, y;
            n = s.size();
            memset(dp, 0, sizeof(dp));
            rep (i, n) {
                if (s[i] == '(') a[i] = -1;
                if (s[i] == ')') a[i] = 1;
                if (s[i] == '[') a[i] = -2;
                if (s[i] == ']') a[i] = 2;
            }
            rep (i, n) dp[i][i] = 1;
            FOR (k, 2, n) {
                FOR (i, 0, n - k) {
                    l = i, r = i + k - 1;
                    dp[l][r] += dp[l][r - 1];
                    if (a[r] > 0) {
                        FORD (j, r - 1, l) {
                            if (a[j] + a[r] == 0) {
                                //sc(j);
                                if (j + 1 == r) y = 1;
                                else y = dp[j + 1][r - 1];
                                if (l > j - 1) x = 1;
                                else x = dp[l][j - 1];
                                dp[l][r] += x * y;
                            }
                        }
                    }
                    //sc3(l, r, dp[l][r]);
                }
            }
            return dp[0][n - 1] - 1;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "()[]"; long long Arg1 = 3LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "())"; long long Arg1 = 2LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "()()"; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "([)]"; long long Arg1 = 2LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "())[]][]([]()]]()]]]"; long long Arg1 = 3854LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
        BracketSequenceDiv1 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
