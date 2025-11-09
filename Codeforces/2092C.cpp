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
    
    int n;
    cin>>n;
    vector<ll> a(n);
    priority_queue<ll> even, odd;
    for(auto &x : a) {
        cin>>x;
        if(x & 1) {
            odd.push(x);
        } else {
            even.push(x);
        }
    }

    if(odd.empty()) {
        cout << even.top() << nl;
        return;
    }

    if(even.empty()) {
        cout << odd.top() << nl;
        return;
    }

    ll ans = 0;
    ans += odd.top();
    odd.pop();

    while(!even.empty() && !odd.empty()) {
        ll k = even.top() + odd.top() - 1;
        even.pop();
        odd.pop();
        even.push(k);
    }

    while(!even.empty()) {
        ans += even.top();
        even.pop();
    }

    ll ans2 = 0;
    for(auto &x : a) {
        if(x & 1) {
            odd.push(x);
        } else {
            even.push(x);
        }
    }

    ans2 += even.top();
    ans2 += odd.top();
    even.pop();
    odd.pop();

    while(!even.empty()) {
        ans2 += even.top();
        even.pop();
    }

    cout << max(ans,ans2) << nl;
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

