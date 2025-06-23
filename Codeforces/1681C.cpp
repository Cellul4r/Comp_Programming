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
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<pi> ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                ans.push_back(make_pair(i,j));
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            } else if(a[i] == a[j] && b[i] > b[j]) {
                ans.push_back(make_pair(i,j));
                swap(b[i],b[j]);
            }
        }
    }

    if(!is_sorted(all(a)) || !is_sorted(all(b))) {
        cout << -1 << nl;
        return;
    }
    cout << ans.size() << nl;
    for(auto &[x,y] : ans) {
        cout << x + 1 << " " << y + 1 << nl;
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

