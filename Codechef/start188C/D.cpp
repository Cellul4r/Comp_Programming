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

void solve(){
    
    int n,k;
    cin>>n>>k;
    vector<pair<int,ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin>>a[i].second;
    }
    auto b = a;
    sort(all(a));
    multiset<ll> save;
    vector<ll> ans(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        //cerr << sum << nl;
        ans[i] = sum;
        if((int)save.size() < k) {
            save.insert(a[i].second);
            sum += a[i].second;
        } else if(*save.begin() < a[i].second){
            sum -= *save.begin();
            save.erase(save.begin());
            save.insert(a[i].second);
            sum += a[i].second;
        }
    }
    for(auto &x : b) {
        cout << ans[x.first-1] << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

