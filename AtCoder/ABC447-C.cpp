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
    
    string s,t; cin>>s>>t;
    s += "Z";
    t += "Z";
    vector<int> a,b;
    int n = s.length(), m = t.length();
    for(int i = 0; i < n; i++) {
        if(s[i] != 'A') {
            a.push_back(i);
        }
    }
    for(int i = 0; i < m; i++) {
        if(t[i] != 'A') {
            b.push_back(i);
        }
    }
    if(a.size() != b.size()) {
        cout << -1;
        return;
    }
    int prvA = -1, prvB = -1;
    ll ans = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        int j = a[i], k = b[i];
        if(s[j] != t[k]) {
            cout << -1;
            return;
        }
        // s[j] = t[k]
        ans += abs((j - prvA - 1) - (k - prvB - 1));
        prvA = j;
        prvB = k;
    }
    cout << ans;
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

