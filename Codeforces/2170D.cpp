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
    
    int n,q;
    cin>>n>>q;
    string s; cin>>s;
    ll ss = 0;
    ll cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
    ll d = 0;
    vector<bool> vis(n,false);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'X') {
            ss += 10;
        } else if(s[i] == 'V') {
            ss += 5;
        } else if(s[i] == 'I') {
            ss += 1; 
        } else {
            d++;
        }
    }

    /*for(int i = 1; i < n - 1; i++) {
        if(s[i] != '?' || s[i-1] != 'I' || (s[i+1] != 'V' && s[i+1] != 'X')) continue;
        cnt1++;
        vis[i] = true;
    }*/

    for(int i = 0; i < n - 1; i++) {
        if(s[i] != '?' || vis[i] || (s[i+1] != 'V' && s[i+1] != 'X')) continue;
        cnt2++;
        vis[i] = true;
    }

    for(int i = 0; i < n - 1; i++) {
        if(s[i] != '?' || vis[i] || s[i+1] != '?' || vis[i+1]) continue;
        cnt4 += 2;
        vis[i] = vis[i+1] = true;
    }

    for(int i = 1; i < n; i++) {
        if(s[i] != '?' || vis[i] || s[i-1] != 'I') continue;
        cnt3++;
        vis[i] = true;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] != '?' || vis[i]) continue;
        cnt5++;
        vis[i] = true;
    }

    cout << ss << nl;
    cout << cnt2 << " " << cnt3 << " " << cnt4 << " " << cnt5 << nl;
    for(int i = 0; i < q; i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        // a X, b V, c I
        ll ans = ss;
        // fill ? V,X
        vector<ll> cnt{cnt2,cnt3,cnt4,cnt5};
        ll k = min(c, cnt[0]);
        cnt[0] -= k;
        c -= k;
        ans -= k;
        cnt[3] += cnt[0];
        
        k = min(c, cnt[2] / 2ll);
        cnt[2] -= k;
        c -= k;
        if(cnt[2] & 1) {
            cnt[3]++;
            cnt[2]--;
        }
        ans += 
        k = min(c, cnt[3]);
        cnt[3] -= k;
        c -= k;
        ans += k;

        cout << ans << nl;
    }
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

