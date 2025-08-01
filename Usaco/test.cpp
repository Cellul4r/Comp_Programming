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
#define x first
#define y second
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
int ans = INT_MAX;
set<pi> a;
vector<pi> l,r,t,b;

int area(set<pi> cows) {

    if(cows.empty()) return 0;
    int ll = INF,rr = 0,tt = 0,bb = INF;
    for(auto &k : cows) {
        //cerr << k.x << " " << k.y << nl;
        ll = min(ll,k.x);
        rr = max(rr,k.x);
        tt = max(tt,k.y);
        bb = min(bb,k.y);
       //cerr << nl;
    }
    return (rr - ll) * (tt - bb);
}
void solve(){

    cin>>n;

    auto LEFT = [&](pi i, pi j) {
        return i.x < j.x;
    };
    auto RIGHT = [&](pi i, pi j) {
        return i.x > j.x;
    };
    auto TOP = [&](pi i, pi j) {
        return i.y > j.y;
    };
    auto BOT = [&](pi i, pi j) {
        return i.y < j.y;
    };

    for(int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        a.insert({x,y});
        l.push_back({x,y});
        r.push_back({x,y});
        t.push_back({x,y});
        b.push_back({x,y});
    }

    sort(all(l), LEFT);
    sort(all(r), RIGHT);
    sort(all(t), TOP);
    sort(all(b), BOT);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                    //cerr << i << " " << j << " " << k << nl;
                vector<int> idx(4);
                idx[i]++;
                idx[j]++;
                idx[k]++;
                auto aa = a;
                for(int z = 0; z < 4; z++) {
                    int run = 0;
                    while(idx[z] != 0) {
                        pi val;
                        if(z == 0) {
                            val = l[run];
                        } else if(z == 1) {
                            val = r[run];
                        } else if(z == 2) {
                            val = t[run];
                        } else {
                            val = b[run];
                        }
                        if(aa.count(val)) {
                            aa.erase(val);
                            idx[z]--;
                        }
                        run++;
                    }
                }
                //cerr << area(aa) << nl;
                ans = min(ans, area(aa));
            }
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    string s = "reduce";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

