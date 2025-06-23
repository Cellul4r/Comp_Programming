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
    
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    ll sum = 0;
    for(auto &x : a) {
        cin>>x;
        sum += x;
    }
    vector<int> lastQuery(n);
    int now = -1, val = -1;
    for(int i = 1; i <= q; i++) {
        int type,x;
        cin>>type;
        if(type == 1) {
            int pos;
            cin>>pos>>x;
            pos--;
            if(lastQuery[pos] > now) {
                sum -= a[pos];
            } else {
                sum -= val; 
            }
            sum += x;
            a[pos] = x;
            lastQuery[pos] = i;
        } else {
            cin>>x;
            sum = 1ll * n * x;
            now = i;
            val = x;
        }
        cout << sum << nl;
    }
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

