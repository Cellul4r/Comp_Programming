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
    vector<int> cnt(n+1);
    vector<int> a(n);
    bool flag = true;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a[i] = x;
        if(x == -1) continue;
        if(cnt[x] != 0) {
            flag = false;
        } else {
            cnt[x]++;
        }
    }

    cout << (flag ? "Yes" : "No") << nl;
    if(!flag) return;
    int cur = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] != -1) continue;
        while(cnt[cur] != 0) {
            cur++;
        }
        cnt[cur] = 1;
        a[i] = cur;
    }
    for(auto &x : a) {
        cout << x << " ";
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

