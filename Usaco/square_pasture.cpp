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

struct Point {

    int x1,y1,x2,y2;
};
Point a,b;
void solve(){
    
    cin>>a.x1>>a.y1>>a.x2>>a.y2;
    cin>>b.x1>>b.y1>>b.x2>>b.y2;
    int width = max(a.x2,b.x2) - min(a.x1,b.x1);
    int height = max(a.y2,b.y2) - min(a.y1,b.y1);
    int l = 1, r = 100;
    int ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(mid >= width && mid >= height && mid * mid >= width * height) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans * ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    string s = "square";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    

    //cin>>t;
    while(t--)solve();

    return 0;
}

