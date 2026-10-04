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
    
    int n,k; cin>>n>>k;
    // 1.) split the array to windows such that each window -> max - min <= k
    //
    // two cases
    // 1.) last element in the window has even frequency -> easy! choose that element and egor win
    // 2.) last element in the window has odd freq -> ? egor will lose if arseniy choose this element
    // 
    vector<ll> cnt(n+1);
    vector<ll> pre(n+1);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] > 0) {
            pre[i] = 1;
        }
        pre[i] += pre[i-1];
    }

    auto f = [&](int l, int r) {
        if(l <= 0) l = 1;
        if(l > r) return 0ll;
        return pre[r] - pre[l-1];
    };
    for(int i = n; i >= 1; i--) {
        if(cnt[i] == 0) continue;
        if(cnt[i] % 2 == 0) {
            cout << "YES\n";
            return;
        }
        // odd frequency egor will lose.
        if(f(i-k, i-1)) {
            cout << "YES\n";
            return;
        }
        i -= k;
    }

    cout << "NO\n";
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

