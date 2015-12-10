// BEGIN CUT HERE

// END CUT HERE
#line 5 "TreeAndPathLength3.cpp"
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

class TreeAndPathLength3 {
        public:
        vector <int> construct(int s) {
            set<int> a;
            set<int> :: iterator it;
            vi ans;
            pii b[40000];
            int e, x, y, tmp, id;
            FOR (i, 1, 150) FOR (j, 1, 150) {
                a.insert(i * j);
                b[i * j] = mp(i, j);
            }
            it = a.lower_bound(s);
            id = *it;
            //sc3(id, b[id].X, b[id].Y);
            if (id == s) {
                ans.pb(0), ans.pb(1);
                e = 2;
                rep (i, b[id].X) ans.pb(0), ans.pb(e + i);
                e = 2 + b[id].X;
                rep (i, b[id].Y) ans.pb(1), ans.pb(e + i);
                return ans;
            }
            --it;
            id = *it;
            x = b[id].X, y = b[id].Y, tmp = s - x * y;
            if (x < y) swap(x, y);
            //sc2(x, y);
            ans.pb(0), ans.pb(1);
            e = 2;
            rep (i, x - 1) ans.pb(0), ans.pb(e + i);
            e = 2 + x - 1;
            //sc(e);
            rep (i, y) ans.pb(1), ans.pb(e + i);
            e += y;
            //sc(e);
            ans.pb(e - 1), ans.pb(e);
            rep (i, tmp) ans.pb(e), ans.pb(e + 1), e++;
            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {0, 1, 1, 2, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 8; int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
        TreeAndPathLength3 ___test;
        //___test.run_test(-1);
        ___test.construct(157);
//        vi a;
//        FOR (i, 1, 150) FOR (j, 1, 150) a.pb(i * j);
//        sort(ALL(a));
//        int tmp = 0;
//        FOR (i, 1, 10000) {
//            int id = lower_bound(ALL(a), i) - a.begin();
//            tmp = max(tmp, i - a[id - 1]);
//        }
//        sc(tmp);
        return 0;
}
// END CUT HERE
