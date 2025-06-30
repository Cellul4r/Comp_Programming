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
    
    int n,m;
    cin>>n>>m;
    vector<int> a(n),p(m);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : p) {
        cin>>x;
        x--;
    }
    sort(all(p));

    auto l = a.begin(), r = a.begin(); 
    for(int i = 0; i < p[0]; i++) {
        l++;
        r++;
    }
    r++;
    for(int i = 1; i < m; i++) {
        if(p[i] - p[i-1] > 1) {
            sort(l, r+1);
            l = a.begin(), r = a.begin();
            for(int j = 0; j < p[i]; j++) {
                l++;
                r++;
            }
            r++;
        } else {
            r++;
        }
    }
    sort(l,r+1);

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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

