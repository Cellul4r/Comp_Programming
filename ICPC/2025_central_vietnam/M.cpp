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
int n;
array<int,2> a[N];
ll ans = LINF;
void solve(){
    
    cin>>n;
    for(int i = 0; i < n+2; i++) {
        cin>>a[i][0]>>a[i][1];
    }

    for(int mask = 0; mask < (1 << n); mask++) {
        vector<int> f,s;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                f.push_back(i);
            } else {
                s.push_back(i);
            }
        }
        ll x = LINF, y = LINF;
        do {
            ll now = 0;
        }while(next_permutatino(f));
        ans = min(ans, x + y);
    }
    cout << ans;
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

