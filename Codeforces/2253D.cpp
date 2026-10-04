/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
string ans;
string now;
int cur = 0;
int p,q;
void recur(int a, int b, int x, int y) {
    if(cur < x + y) {
        cur = x + y;
        ans = now;
    }
    //cout << y + 1 << " " << q << nl;
    if(y+b+1 <= q) {
        now += 'Y';
        recur(a, b+1, x, y+b+1);
        now.pop_back();
    }
    cout << now << " " << a << " " << b << " " << x << " " << y << nl;
    int i = 1;
    for(;; i++) {
        if(x + a*i > p) break;
        if(y + 1ll * (b+i-1)*(b+i) / 2ll - (b-1)*b / 2ll > q) break;
        now += 'X'; 
        now += 'Y';
        int xx = x + a * i;
        int yy = y + 1ll * (b+i-1)*(b+i) / 2ll - (b-1)*b / 2ll;
        recur(a+1,b+i-1, xx, yy);
        now.pop_back();
    }
    for(int j = 1; j < i; j++) {
        now.pop_back();
    }
}
void solve(){
    
    // (p+q) - (x+y) is minimum as possible
    // thus we need to find x+y that is also maximum!
    cin>>p>>q;
    cur = 0;
    ans.clear();
    now.clear();
    recur(0,0,0,0);
    cout << ans << nl;
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

