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

int digit(int x) {
    int cnt = 0;
    while(x) {
        x /= 10;
        cnt++;
    }
    return cnt;
}
void solve(){
    
    int n;
    cin>>n;
    map<int,int> cnt1, cnt2;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        //a.insert(x);
        cnt1[x]++;
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(cnt1[x] > 0) {
            cnt1[x]--;
            continue;
        }
        cnt2[x]++;
    }
    for(auto &x : cnt1) {
        if(x.first <= 9) continue;
        int k = digit(x.first);
        ans += x.second;
        cnt1[k] += x.second;
        x.second = 0;
    }
    for(auto &x : cnt2) {
        if(x.first <= 9) continue;
        int k = digit(x.first);
        ans += x.second;
        cnt2[k] += x.second;
        x.second = 0;
    }
    //cerr << ans << nl;
    for(auto &x : cnt2) {
        int k = min(cnt1[x.first], x.second);
        cnt1[x.first] -= k;
        x.second -= k;
        if(x.first != 1) {
            ans += cnt1[x.first] * digit(x.first);
            ans += x.second * digit(x.first);
            cnt1[x.first] = 0;
            x.second = 0;
        }
    }
    for(auto &x : cnt1) {
        if(x.first == 1) continue;
        ans += x.second * digit(x.first);
    }
    cout << ans << nl;
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

