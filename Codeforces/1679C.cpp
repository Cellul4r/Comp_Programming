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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

struct fenwick {
    int n;
    vector<int> bit;

    fenwick(int n) {
        this->n = n+1;
        bit.resize(n+1, 0);
    }
    
    fenwick(vector<int>& a) : fenwick(a.size()) {
        for(int i = 0; i < n; i++) {
            add(i, a[i]);
        }
    }

    int sum(int r) {
        int res = 0;
        for(; r > 0; r -= r & -r) {
            res += bit[r]; 
        }
        return res;
    }
    
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx, int v) {
        for(; idx < n; idx += idx & -idx) {
            bit[idx] += v;
        }
    }
};
void solve(){
    
    int n,q;
    cin>>n>>q;

    fenwick f1(n),f2(n);
    vector<ll> row(n+1), col(n+1);
    for(int i = 0; i < q; i++) {
        int t;
        cin>>t;
        if(t == 1) {
            int x,y;
            cin>>x>>y;
            //x--,y--;
            row[x]++;
            col[y]++;
            if(row[x] == 1) f1.add(x,1);
            if(col[y] == 1) f2.add(y,1); 
        } else if(t == 2) {
            int x,y;
            cin>>x>>y;
            //x--,y--;
            row[x]--;
            col[y]--;
            if(row[x] == 0) f1.add(x,-1); 
            if(col[y] == 0) f2.add(y,-1); 
        } else {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            //a--,b--,c--,d--;
            ll x = f1.sum(a,c); 
            ll y = f2.sum(b,d); 
            //cerr << x << " CHECK " << y << nl;
            if(x == c - a + 1 || y == d - b + 1) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

