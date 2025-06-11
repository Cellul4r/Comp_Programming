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
    for(auto &x : a) cin>>x;
    vector<int> ans(n);

    auto f = [&](int paint) {
        cerr << paint << nl;
        vector<int> colors(n+1, 1);
        vector<int> now(n);
        vector<int> vis(k+1);
        set<int> canPaint;
        for(int i = 1; i <= k; i++) {
            canPaint.insert(i);
        }
        for(int i = 0; i < n; i++) {
            int& x = a[i];
            /*while(colors[x] <= k && vis[colors[x]] == paint) {
                colors[x]++;
            }*/
            if(canPaint.empty()) continue;
            colors[x] = max(colors[x], *canPaint.begin());
            if(colors[x] > k) continue;
            vis[colors[x]]++;
            if(vis[colors[x]] == paint) {
                canPaint.erase(colors[x]);
            }
            cerr << i << " " << colors[x] << nl;
            now[i] = colors[x]++;
        }
        cerr << nl;
        for(int i = 1; i <= k; i++) {
            if(vis[i] != paint) {
                return false;
            }
        }
        ans = now;
        return true;
    };
    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    //cout << l << nl;
    for(auto &x : ans) {
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

