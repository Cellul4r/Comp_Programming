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
    
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int n;
    string s;
    cin>>n>>s;
    vector<ll> preX(n+1), preY(n+1);
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == 'U') {
            preY[i] = 1;
        } else if(s[i-1] == 'D') {
            preY[i] = -1;
        } else if(s[i-1] == 'L') {
            preX[i] = -1;
        } else {
            preX[i] = 1;
        }
        preX[i] += preX[i-1];
        preY[i] += preY[i-1];
    }

    auto f = [&](ll days) {
        ll need = 0;        
        ll x = x1, y = y1;
        x += 1ll * (days / n) * preX[n] + (preX[days % n]);
        y += 1ll * (days / n) * preY[n] + (preY[days % n]);
        need = llabs(x-x2) + llabs(y-y2);
        return need <= days;
    };

    ll l = 0, r = 1e15;
    while(l < r) {
        ll mid = l + (r - l) / 2ll;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << (f(l) ? l : -1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

