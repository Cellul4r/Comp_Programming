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
    string s;
    vector<int> a(n);
    vector<ll> pre(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        a[i]--;
        pre[min(i,a[i])]++;
        pre[max(i,a[i])]--;
    }
    for(int i = 1; i < n; i++) pre[i] += pre[i-1];
    cin>>s;

    ll sum = 0;
    for(int i = 0; i < n-1; i++) {
        if(s[i] == 'L' && s[i+1] == 'R') {
            sum += pre[i];
        }
    }
    for(int i = 0; i < q; i++) {
        int k;
        cin>>k;
        k--;
        if(k > 0 && s[k-1] == 'L' && s[k] == 'R') sum -= pre[k-1];
        if(k < n - 1 && s[k] == 'L' && s[k+1] == 'R') sum -= pre[k];
        s[k] = (s[k] == 'L' ? 'R' : 'L');
        if(k > 0 && s[k-1] == 'L' && s[k] == 'R') sum += pre[k-1];
        if(k < n - 1 && s[k] == 'L' && s[k+1] == 'R') sum += pre[k];
        cout << (sum ? "NO" : "YES") << nl;
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

