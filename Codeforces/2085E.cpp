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

void solve(){
    
    int n;
    cin>>n;
    vector<ll> a(n);
    multiset<ll> b;
    ll y = 0, z = 0;
    for(auto &x : a) {
        cin>>x;
        y += x;
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        b.insert(x);
        z += x;
    }

    cerr << y << " " << z << nl;

    for(int i = 1; i <= (int)1e6; i++) {
        if(y % i != z % i) {
            continue;
        }
        multiset<ll> c = b;    
        for(auto &x : a) {
            if(c.count(x % i)) {
                c.erase(c.find(x%i));
            }
        }
        if(c.empty()) {
            cout << i << nl;
            return;
        }
    }

    cout << -1 << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

