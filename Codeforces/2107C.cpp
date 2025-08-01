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
const ll LINF = 1e12+10;

void solve(){
    
    int n;
    ll k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            a[i] = -1e13;
        }
    }
    vector<ll> pre(n+1), suff(n+2);
    
    ll maxSum = 0;
    for(int i = 1; i <= n; i++) {
        pre[i] = max(a[i-1], pre[i-1] + a[i-1]);
        maxSum = max(maxSum, pre[i]);
    }

    for(int i = n; i >= 1; i--) {
        suff[i] = max(a[i-1], suff[i+1] + a[i-1]);
    }

    
    if(maxSum == k) {
        cout << "YES" << nl;
        for(auto &x : a) {
            cout << x << " ";
        }
        cout << nl;
        return; 

    }
    
    if(maxSum > k) {
        cout << "NO" << nl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') continue;
        ll l = pre[i], r = suff[i+2];
        if(l < 0) l = 0;
        if(r < 0) r = 0;
        cout << "YES" << nl;
        a[i] = k - (l + r);
        for(auto &x : a) {
            cout << x << " ";
        }
        cout << nl;
        return; 
    }

    cout << "NO" << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

