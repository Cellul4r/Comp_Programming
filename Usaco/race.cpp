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

ll k;
int n;
ll sum(ll n) { return n * (n + 1) / 2ll; }
ll S(ll a, ll b) { return sum(b) - sum(a);}
ll test(ll v, ll x, ll dist) {
    if(v <= x) return true;
    ll remain = S(x-1,v);
    return remain <= dist;
}
void solve(){

    cin>>k>>n;
    for(int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        // at finish line speed <= x 
        // if x = 1 what could we do?
        // then we just increase the speed to 1 and finish the line
        ll now = k, speed = 0;
        ll ans = 0;
        while(now > 0) {
            ans++;
            //cerr << speed << " " << now << nl;
            if(test(speed + 1, x, now)) {
                speed++;
            } else if(test(speed, x, now)) {

            } else {
                speed--;
            }
            now -= speed;
            //cerr << speed << " " << now << nl;
            //cerr << nl;
        }
        cout << ans << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

