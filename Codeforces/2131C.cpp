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
    
    int n,k; cin>>n>>k;
    multiset<int> a;
    vector<int> b;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a.insert(x);
    }
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        if(a.count(x)) {
            a.erase(a.find(x));
            continue;
        }
        b.push_back(x);
    }
    map<int,int> s,t;
    for(auto &x : a) {
        s[x % k]++;
    }
    for(auto &x : b) {
        t[x % k]++;
    }

    for(auto &[x,y] : s) {
        int now = min(y, t[x]);
        y -= now;
        t[x] -= now;
    }
    for(auto &[x,y] : s) {
        int now = min(y, t[k-x]);
        y -= now;
        t[k-x] -= now;
    }
    bool flag = true;
    for(auto &[x,y] : s) {
        if(y > 0) {
            flag = false;
            break;
        }
    }
    for(auto &[x,y] : t) {
        if(y > 0) {
            flag = false;
            break;
        }

    }
    cout << (flag ? "YES" : "NO") << nl;
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

