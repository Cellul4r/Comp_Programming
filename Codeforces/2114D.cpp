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

ll findArea(vector<pi>& a, int c, int d) {
    
    int l = INF, r = 0, t = INF, b = 0;
    for(auto &x : a) {
        if(x.first == c && x.second == d) continue;
        l = min(l,x.second);
        r = max(r,x.second);
        t = min(t,x.first);
        b = max(b,x.first);
    }
    int n = a.size() - 1;
    ll area = 1ll * (r - l + 1) * (1ll * b - t + 1);
    if(area == n) {
        //cerr << min(1ll * (r - l + 2) * (1ll * b - t + 1), 1ll * (r - l + 1) * (1ll * b - t + 2)) << nl;
        return min(1ll * (r - l + 2) * (1ll * b - t + 1), 1ll * (r - l + 1) * (1ll * b - t + 2));
    } else {
        //cerr << area << nl;
        return area;
    }
}
void solve(){
    
    int n;
    cin>>n;
    vector<pi> top,left,right,bottom;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        top.push_back(make_pair(x,y));
        left.push_back(make_pair(x,y));
        right.push_back(make_pair(x,y));
        bottom.push_back(make_pair(x,y));
    }
    if(n == 1) {
        cout << 1 << nl;
        return;
    }
    auto l = [&](pi i, pi j) {
        return i.second < j.second;
    };
    auto r = [&](pi i, pi j) {
        return i.second > j.second;
    };
    auto t = [&](pi i, pi j) {
        return i.first < j.first;
    };
    auto b = [&](pi i, pi j) {
        return i.first > j.first;
    };
    sort(all(top), t);
    sort(all(left), l);
    sort(all(right), r);
    sort(all(bottom), b);
    ll ans = LINF;
    ans = min(ans, findArea(top, top[0].first, top[0].second));
    ans = min(ans, findArea(top, left[0].first, left[0].second));
    ans = min(ans, findArea(top, right[0].first, right[0].second));
    ans = min(ans, findArea(top, bottom[0].first, bottom[0].second));
    cout << ans << nl;
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

