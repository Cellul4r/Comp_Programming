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

struct Rect {
    ll x1,y1,x2,y2;
};

double distance(ll x1, ll y1, ll x2, ll y2) {
    
    return sqrt((double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve(){
    
    ll W,H;
    cin>>W>>H;
    Rect a; 
    cin>>a.x1>>a.y1>>a.x2>>a.y2;
    ll w,h;
    cin>>w>>h;

    double ans = (double)INF;
    // try to move horizantal
    ll left = a.x1, right = W - a.x2;
    ll k = min(left + right, w);
    if(k >= w) {
        // ok
        if(h > H) {
            cout << -1 << nl;
            return;
        } else {
            ll x = max(0ll, w - right);
            if(left >= x) {
                ans = min(ans, distance(a.x1,a.y1,a.x1-x,a.y1));
            }
            x = max(0ll, w - left);
            if(right >= x) {
                ans = min(ans, distance(a.x1,a.y1,a.x1+x,a.y1));
            }
        } 
    }
    ll top = a.y1, bottom = H - a.y2;
    k = min(top + bottom, h);
    if(k >= h) {
        if(w > W) {
            cout << -1 << nl;
            return;
        }  else {
            ll x = max(0ll,h - bottom);
            if(top >= x) {
                ans = min(ans, distance(a.x1,a.y1,a.x1,a.y1-x));
            }
            x = max(0ll,h - top);
            if(bottom >= x) {
                ans = min(ans, distance(a.x1,a.y1,a.x1,a.y1+x));
            }
        }

    }
    
    if(ans == INF) {
        cout << -1 << nl;
        return;
    }
    cout << fixed << setprecision(9) << ans << nl;
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

