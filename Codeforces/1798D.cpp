/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    
    // mn = 0 -> then all elements in the array is equal to 0 -> answer = NO

    // mx(Sum) < mx - min
    int n; cin>>n;
    // mx(abs(a[l]+...+a[r])
    // mx(abs(p[r] - p[l-1])) < mx - min
    // = mxPrefix - mnPrefix (including 0)
    // mxPre - mnPre < mx - mn
    // mxPre - mx < mnPre - mn
    ll mx = INT_MIN, mn = INT_MAX;
    deque<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(mn == 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    a.pop_front();
    ll s = 0;
    sort(all(a));
    for(int i = 1; i <= n; i++) {
        if(s > 0) {
            s += a.front();
            cout << a.front() << " ";
            a.pop_front();
        } else {
            s += a.back();
            cout << a.back() << " ";
            a.pop_back();
        }
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

