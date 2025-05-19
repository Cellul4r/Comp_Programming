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

    ll areaIntersect(Rect b) {
        ll width = max(0ll, min(x2,b.x2) - max(x1,b.x1));
        ll height = max(0ll, min(y2,b.y2) - max(y1,b.y1));
        return width * height;
    }

    ll areaIntersect2(Rect b, Rect c) {
        ll xx2 = min(x2, b.x2);
        ll xx1 = max(x1,b.x1);
        ll yy2 = min(y2,b.y2);
        ll yy1 = max(y1,b.y1);
        Rect k{xx1,yy1,xx2,yy2};
        return k.areaIntersect(c);
    }
    ll area() {
        return (x2 - x1) * (y2 - y1);
    }
};
Rect a,b,c;
void solve(){
    
    cin>>a.x1>>a.y1>>a.x2>>a.y2;
    cin>>b.x1>>b.y1>>b.x2>>b.y2;
    cin>>c.x1>>c.y1>>c.x2>>c.y2;

    ll ans = a.area() - a.areaIntersect(b) - a.areaIntersect(c) + a.areaIntersect2(b,c);
    cout << (ans > 0 ? "YES" : "NO");
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

    //cin>>t;
    while(t--)solve();

    return 0;
}

