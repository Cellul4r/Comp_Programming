#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;
int n;
const int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
void solve() {
    
    ll a,b,d;
    cin>>a>>b>>d;
    map<pair<int,pi>, ll> dis;
    set<pi> trap;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        trap.insert(make_pair(x,y));
    }
    
    ll cur = 0;
    int k = 0;
    dis[make_pair(k,make_pair(a,b))] = cur;
    bool found = false;
    while(d > 0) {
        ll x = a + dx[k];
        ll y = b + dy[k];
        if(x < 0 || x > 100 || y < 0 || y > 100) {
            a += d * dx[k];
            b += d * dy[k];
            break;
        }
        if(trap.count(make_pair(x,y))) {
            k++;
            k %= 4;
            continue;
        }

        d--;
        a = x;
        b = y;
        if(!found && dis.find(make_pair(k,make_pair(x,y))) != dis.end()) {
            // found cycle
            found = true;
            ll cycle = cur + 1 - dis[make_pair(k,make_pair(x,y))];
            d %= cycle;
        } else {
            dis[make_pair(k,make_pair(a,b))] = ++cur;
        }
    }
    cout << a << " " << b << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n) {
        if(n == 0) break;
        solve();
    }
    return 0;
}
