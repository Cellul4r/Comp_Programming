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
    
    int n;
    string s;
    cin>>n>>s;
    int a = 0, b = 0;
    for(auto &x : s) {
        if(x == '(') a++;
        else b++;
    }
    if(a != b) {
        cout << -1;
        return;
    }

    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1];
        p[i] += (s[i-1] == '(' ? 1 : -1);
    }
    int ans = 0;
    int l=-1;
    for(int i = 2; i <= n; i++) {
        if(p[i-1] == 0 && p[i] < 0) {
            l = i;
        } else if(p[i-1] < 0 && p[i] == 0) {
            ans += i - l;
        }
    }
    cout << ans << nl;
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

