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
    
    int n; cin>>n;

    vector<int> a(n);
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i] & 1) {
            odd++;
        } else {
            even++;
        }
    }

    if(odd && even) {
        sort(all(a));
    }
    for(auto &x : a) {
        cout << x << " ";
    }
    // 1 1 3 5 7 9
    // 2 2 4 6
    // 1 6 4 2
    // 2 6 4 1
    // 2 1 4 6
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

