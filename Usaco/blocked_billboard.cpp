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

int a,b,c,d;
int e,f,g,h;
int i,j,k,l;

bool overlap(int a, int b, int c, int d, int e, int f, int g, int h) {

    if(e > c || a > g) {
        return false;
    }
    if(f > d || b > h) {
        return false;
    }
    return true;
}

int intersect(int a, int b, int c, int d, int e, int f, int g, int h) {
    int x = min(c,g) - max(a,e);
    int y = min(d,h) - max(b,f);
    return x * y;
}
void solve(){
    
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;  
    int ans = (c - a) * (d - b) + (g - e) * (h - f);
    if(overlap(a,b,c,d,i,j,k,l)) {
        ans -= intersect(a,b,c,d,i,j,k,l); 
    }
    if(overlap(e,f,g,h,i,j,k,l)) {
        ans -= intersect(e,f,g,h,i,j,k,l);
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

