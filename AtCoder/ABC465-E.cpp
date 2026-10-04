/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 998244353;

void setIO(string);
int r[505], n;
ll dp[505][2][2][3][2][2ll<<10];
ll solve(int pos, bool tight, bool started, int mod3, bool has3, int mask) {
	if (pos == n) {
        if (!started) return 0;          // exclude 0

        bool A = (mod3 == 0);
        bool B = has3;
        bool C = (__builtin_popcount(mask) == 3);

        return (A + B + C == 1);
    }

    ll &res = dp[pos][tight][started][mod3][has3][mask];
    if (res != -1) return res;

    res = 0;

    int lim = tight ? r[pos] : 9;

    for (int d = 0; d <= lim; d++) {

        bool ntight = tight && (d == lim);
        bool nstarted = started || (d != 0);

        int nmod3 = mod3;
        bool nhas3 = has3;
        int nmask = mask;

        if (nstarted) {
            nmod3 = (mod3 + d) % 3;
            if (d == 3) nhas3 = true;
            nmask |= (1 << d);
        }

        res += solve(pos + 1,
                     ntight,
                     nstarted,
                     nmod3,
                     nhas3,
                     nmask);

        res %= 998244353;
    }

    return res;
}
string s;
void solve(){
    cin>>s; 
    n = s.size();
    for(int i = 0; i < n; i++) {
        r[i] = s[i] - '0';
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, true, false, 0, false, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

