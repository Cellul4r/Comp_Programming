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
    
    ll n,m; cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll>(26));
    vector<ll> sum(26);
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin>>s[i];
        for(auto &x : s[i]) {
            a[i][x-'A']++;
            sum[x-'A']++;
        }
    }

    auto f = [&](int i, int k) {
        if(k < 0) return false;
        for(int j = 0; j < 26; j++) {
            if(sum[j] * m < a[i][j] + sum[j] * k) {
                return false;
            }
        }
        return true;
    };
    vector<int> need(26);
    for(int i = 0; i < n; i++) {
        int l = -1, r = m;
        for(auto &x : s[i]) {
            sum[x-'A']--;
        }
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            //cout << mid << nl;
            if(f(i,mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        for(auto &x : s[i]) {
            sum[x-'A']++;
        }
        cout << l << " ";
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

