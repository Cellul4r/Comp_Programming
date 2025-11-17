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
    priority_queue<int> pq;
    vector<int> cnt(101);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }

    for(int i = 1; i <= 100; i++) {
        pq.push(cnt[i]); 
    }

    ll now = 0, ans = 0;
    while(!pq.empty()) {
        int x = pq.top();
        //cerr << x << " : " << now << nl;
        pq.pop();
        if(x < k) {
            if(k - x > now) {
                ans += x;
                continue;
            }
            now = now + x - 1;
        } else {
            ll val = x / k; 
            now += val * (k - 1);
            x = x % k;
            pq.push(x);
        }
    }
    cout << ans + now << nl;
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

