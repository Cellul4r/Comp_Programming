/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    // b[1] = a[1]
    // b[2] = a[2] - a[1] -> a[2] = a[1] + b[2]
    // b[3] = a[3] - a[2] -> a[3] = b[1] + b[2] + b[3]
    // total sum of b > 0    
    // need lex smallest of a
    // need Sum such that S + a[i] 
    ll sum = 0;
    multiset<ll> save;
    for(int i = 0; i < n; i++) {
        ll x; cin>>x;
        sum += x;
        save.insert(x);
    }
    if(sum <= 0) {
        cout << -1 << nl;
        return;
    }
    sum = 0;
    vector<ll> a;
    for(int i = 0; i < n; i++) {
        // need to find smallest element x such that sum + x >= 1 -> x >= 1 - sum
        auto it = save.lower_bound(1 - sum);

        if(it == save.end()) {
            cout << -1 << nl;
            return;
        }
        sum += *it;
        a.push_back(sum);
        save.erase(it);
    }
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

