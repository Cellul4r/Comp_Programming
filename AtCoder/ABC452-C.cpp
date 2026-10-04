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
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i]>>b[i];
        b[i]--;
    }
    int m; cin>>m;
    vector<string> ss(m+1);
    for(int i = 1; i <= m; i++) {
        cin>>ss[i];
    }
    
    vector<vector<ll>> sum(n+1, vector<ll>(26, 0));
    for(int i = 1; i <= m; i++) {
        auto s = ss[i];
        for(int i = 1; i <= n; i++) {
            if(a[i] != (int)s.size()) continue;
            sum[i][s[b[i]] - 'a']++;
        }
    }

    for(int i = 1; i <= m; i++) {
        bool ok = true;
        auto s = ss[i];
        if((int)s.size() != n) {
            ok = false;
        } else {
            for(int j = 1; j <= n; j++) {
                if(sum[j][s[j-1]-'a'] == 0) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "Yes" : "No");
        cout << nl;
    }
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

