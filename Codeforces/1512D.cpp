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
    vector<int> a(n+2);
    ll sum = 0;
    for(int i = 0; i < n+2; i++) {
        cin>>a[i];
        sum += a[i];
    }
    sort(all(a));
    auto check = [&](int idx) {
        int s = a[idx];
        sum -= s;
        ll diff = sum - s;
        int ans = -1;
        for(int i = 0; i < n + 2; i++) {
            if(i == idx) continue;
            if(a[i] == diff) {
                ans = i;
                break;
            }
        }
        sum += s;
        return ans;
    };

    int idx = check(n+1);
    int chose = n + 1;
    if(idx == -1) {
        idx = check(n);
        chose = n;
    }
    if(idx == -1) {
        cout << -1 << nl;
        return;
    }

    for(int i = 0; i < n + 2; i++) {
        if(i == idx || i == chose) continue;
        cout << a[i] << " ";
    }
    cout << nl;
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

