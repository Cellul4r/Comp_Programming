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
    int x1,y1,x2,y2;

    int areaIntersect(Rect b) {
        int width = max(0, min(x2,b.x2) - max(x1,b.x1));
        int height = max(0, min(y2,b.y2) - max(y1,b.y1));
        return abs(width * height);
    }
};
Rect a, b;
void solve(){

    cin>>a.x1>>a.y1>>a.x2>>a.y2;
    cin>>b.x1>>b.y1>>b.x2>>b.y2;

    int ans = abs(a.x2 - a.x1) * abs(a.y2 - a.y1);
    if (b.y1 <= a.y1 && a.y2 <= b.y2) {
        if(b.x1 <= a.x1 || b.x2 >= a.x2) {
            ans -= a.areaIntersect(b);
        } 
    }

    // Case 2: Cow feed billboard covers all width of lawnmower billboard
    else if (b.x1 <= a.x1 && a.x2 <= b.x2) {
        if(b.y1 <= a.y1 || b.y2 >= a.y2) {
            ans -= a.areaIntersect(b);
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    string s = "billboard";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

