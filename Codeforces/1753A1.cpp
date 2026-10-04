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
    int pos = 0, neg = 0;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(a[i] == 1) pos++;
        else neg++;
    }
    if(pos == neg) {
        cout << n << nl;
        for(int i = 1 ; i<= n; i++) {
            cout << i << " " << i << nl;
        }
        return;
    }
    int type = 0;
    if(pos > neg) type = 1;
    vector<array<int,2>> ans;
    for(int i = 1; i <= n; i++) {
        if(i == n || pos == neg) {
            ans.push_back({i,i});
            continue;
        }
        if(type == 0) {
            if(a[i] == 1 && a[i+1] == -1) {
                ans.push_back({i,i+1});
                pos++;
                neg--;
                i++;
            } else if(a[i] == -1 && a[i+1] == -1) {
                ans.push_back({i,i+1});
                pos++;
                neg--;
                i++;
            } else {
                ans.push_back({i,i});
                continue;
            }
        } else {
            if(a[i] == -1 && a[i+1] == 1) {
                ans.push_back({i,i+1});
                pos--;
                neg++;
                i++;
            } else if(a[i] == 1 && a[i+1] == 1) {
                ans.push_back({i,i+1});
                pos--;
                neg++;
                i++;
            } else {
                ans.push_back({i,i});
                continue;
            }
        }
    }
    if(pos != neg) {
        cout << -1 << nl;
        return;
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x[0] << " " << x[1] << nl;
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

