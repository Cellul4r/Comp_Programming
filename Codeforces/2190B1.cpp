/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    string s; cin>>s;

    vector<int> nx(n+1, n+1);
    vector<int> suf(n+1, 0);
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '(') {
            nx[i] = i;
        } else {
            nx[i] = nx[i+1];
        }
        if(s[i] == '(') suf[i]++;
        suf[i] += suf[i+1];
    }
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == ')' && nx[i] <= n) {
            int need = nx[i] - i;
            if(suf[nx[i]+1] >= need) {
                ans = max(ans, n - 2 * need);
            }
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

