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
    
    vector<pi> a(3);
    for(int i = 0; i < 3; i++) {
        cin>>a[i].first>>a[i].second;
    }

    bool one = false, two = false, three = false, four = false;

    if(a[0].first == a[1].first && a[1].first == a[2].first && a[0].second + a[1].second + a[2].second == a[0].first) {
        one = true;
    }
    if(a[0].second == a[1].second && a[1].second == a[2].second && a[0].first + a[1].first + a[2].first == a[0].second) {
        two = true;
    }

    if(a[1].second == a[2].second && a[0].first == a[1].first + a[2].first && a[0].first == a[0].second + a[1].second) {
        three = true;
    }
    if(a[1].first == a[2].first && a[0].second == a[1].second + a[2].second && a[0].second == a[0].first + a[1].first) {
        four = true;
    }
    one = one || two || three || four;
    cout << (one ? "YES" : "NO") << nl;
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

