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
    
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    sort(all(a));
    k = min(k, k%2+2);
    auto f = [&]() {
        int mex = 0;
        vector<int> cnt(n+1);
        for(auto &x : a) {
            cnt[x]++;
            if(x == mex) mex++;
        }
        for(auto &x : a) {
            if(cnt[x] == 1 && x < mex) {
                continue;
            }
            x = mex;
        }
    };

    for(int i = 0; i < k; i++) f();
    ll sum = 0;
    for(auto &x : a) sum += x;
    cout << sum << nl;
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

