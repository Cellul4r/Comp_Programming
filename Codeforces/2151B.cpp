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
    
    int n,m; cin>>n>>m;
    string s; cin>>s;
    set<int> a; 
    for(int i = 0; i < m; i++) {
        int x; cin>>x;
        a.insert(x);
    }
    
    int cur = 1;
    bool b = false;
    for(auto &x : s) {
        if(b) {
            while(a.count(cur)) {
                cur++;
            }
        }
        b = false;
        if(x == 'A') {
            cur++;
        } else {
            while(a.count(++cur)) {
            }
        }
        a.insert(cur);
        if(x == 'B') {
            b = true;
        }
    }
    cout << a.size() << nl;
    for(auto &x : a) {
        cout << x << " ";
    }
    cout << nl;
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

