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
    cin>>n;
    vector<int> a(n), b(n), ord(n), cnt(n+1, -1);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
                return a[i] < a[j];
            });

    for(auto &i : ord) {
        cnt[a[i]] = i;
    }

    vector<pi> ans;
    // transform a[i] to b[i] using a[j]
    for(auto &i : ord) {
        if(a[i] > b[i]) {
            cout << -1 << nl;
            return;
        }
        if(a[i] == b[i]) {
            continue;
        }
        if(cnt[b[i]] == -1) {
            cout << -1 << nl;
            return;
        }
        ans.push_back(make_pair(i, cnt[b[i]]));
        a[i] = b[i];
    }

    sort(all(ord), [&](int i, int j) {
                return b[i] > b[j];
            });
    // transform a[i] to b[i] using b[j]
    for(auto &i : ord) {
        if(a[i] > b[i]) {
            cout << -1 << nl;
            return;
        }
        if(a[i] == b[i]) {
            cnt[b[i]] = i;
            continue;
        }
        if(cnt[b[i]] == -1) {
            cout << -1 << nl;
            return;
        }
        ans.push_back(make_pair(i, cnt[b[i]]));
        a[i] = b[i];
    }

    cout << ans.size() << nl;
    for(auto &[x,y] : ans) {
        cout << x + 1 << " " << y + 1 << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

