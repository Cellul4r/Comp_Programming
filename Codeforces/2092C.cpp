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
    vector<ll> even, odd;
    for(auto &x : a) {
        cin>>x;
        if(x & 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    sort(all(odd));
    sort(all(even));
    int k = odd.size(), m = even.size();
    ll ans1 = 0, ans2 = 0;
    if(!odd.empty()) {
        ans1 = odd[k-1];
        for(int i = 0; i < m; i++) {
            ans1 += even[i];
            if(ans1 % 2 == 0) break;
        }
    }
    if(!even.empty()) {
        ans2 = even[m-1];
        for(int i = 0; i < k; i++) {
            ans2 += odd[i];
            if(ans2 % 2 == 1) break;
        }
    }
    cout << max(ans1,ans2) << nl;
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

