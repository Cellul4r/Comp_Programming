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
ll ask(int k, int l, int r) {
    cout << "? " << k;
    for(int i = l; i <= r; i++) {
        cout << " " << i;
    }
    cout << endl;
    ll x;
    cin>>x;
    return x;
}

void answer(int x) {
    cout << "! " << x << endl;
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> pre(n);
    for(auto &x : a) {
        cin>>x;
    }

    pre[0] = a[0];
    for(int i = 1; i < n; i++) pre[i] += a[i] + pre[i-1];
    int l = 0, r = n - 1; 
    while(l < r) {
        int mid = l + (r - l) / 2;
        ll x = ask(mid + 1, 1, mid + 1);
        //cerr << mid << " " << pre[mid] << nl;
        if(x == pre[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    answer(l+1);
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

