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

void test(int n, vector<int> a) {

    int cnt = 0;
    deque<int> now;
    for(int i = 0; i < n; i++) {
        now.push_back(a[i]);
    }
    while(true) {
        deque<int> b = now;
        sort(all(b));
        reverse(all(b));
        if(now == b) break;
        cnt++;
        int x = now.front();
        now.pop_front();
        int y = now.front();
        now.pop_front();
        cerr << x << " " << y << nl;
        if(x > y) {
            now.push_front(x);
            now.push_back(y);
        } else {
            now.push_front(y);
            now.push_back(x);
        }
    }
    cerr << cnt << nl;
}
void solve(){

    int n,q;
    cin>>n>>q;
    vector<int> a(n), to(n+1);
    int idx = 1;
    deque<int> now;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        now.push_back(a[i]);
        to[a[i]] = i;
        if(a[i] == n) {
            idx = i;
        }
    }
    //test(n,a);
    map<int,vector<int>> cnt;
    for(int i = 0; i < idx-1; i++) {
        int x = now.front();
        now.pop_front();
        int y = now.front();
        now.pop_front();
        if(x > y) {
            now.push_front(x);
            now.push_back(y);
            cnt[x].push_back(i+1);
        } else {
            now.push_front(y);
            now.push_back(x);
            cnt[y].push_back(i+1);
        }
    }

    while(q--) {
        int i,k;
        cin>>i>>k;
        int x = a[--i];
        ll ans = 0;
        int j = upper_bound(all(cnt[x]), k) - cnt[x].begin();
        //cerr << j << nl;
        ans += j;
        if(k >= idx && x == n) {
            ans += k - idx + 1;
            if(idx == 0) ans--;
        }
        cout << ans << nl;
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

    cin>>t;
    while(t--)solve();

    return 0;
}

