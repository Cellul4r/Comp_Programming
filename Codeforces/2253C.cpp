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
    
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    // suppose there are n rows -> <= n distinct number from array a
    // similary tehre are m cols -> <= m distinct number from array b
    // max -> n * m distinct number from a + b -> S <= (n+m)*(n+m+1) / 2
    // 6 7 9 10 12 13 15 16 18 (4) (3)
    // 6 8 9 11 12 14 15 17 (5) (2)
    vector<int> a(x),b(y);
    for(int i = 0; i < x; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < y; i++) {
        cin>>b[i];
    }
    ll ans = 0;
    deque<int> aa,bb;
    int i = x - 1, j = y - 1;
    for(int cnt = 0; i >= 0 && cnt < n; i--, cnt++) {
        aa.push_back(a[i]); 
    }
    for(int cnt = 0; j >= 0 && cnt < m; j--, cnt++) {
        bb.push_back(b[j]);
    }
    vector<bool> vis(n+m+1, false);
    int cnt = 0;
    while(cnt < n + m - 1 && !aa.empty() && !bb.empty()) {
        int l = aa.front(), r = bb.front();
        if(vis[l]) {
            aa.pop_front();
            continue;
        }
        if(vis[r]) {
            bb.pop_front();
            continue;
        }
        if(l > r) {
            ans += l;
            aa.pop_front();
            vis[l] = true;
            cnt++;
        } else if(l < r) {
            ans += r; 
            bb.pop_front();
            vis[r] = true;
            cnt++;
        } else {
            ans += l;
            vis[l] = true;
            cnt++;
            if(i < 0 && j < 0) {
                continue; 
            }
            if(i >= 0 && j >= 0) {
                if(a[i] >= b[j]) {
                    aa.pop_front();
                    aa.push_back(a[i--]);
                } else {
                    bb.pop_front();
                    bb.push_back(b[j--]);
                }
                continue;
            }
            if(i >= 0) {
                aa.pop_front();
                aa.push_back(a[i--]);
            } else {
                bb.pop_front();
                bb.push_back(b[j--]);
            }
        }
    }
    while(cnt < n + m - 1 && !aa.empty()) {
        if(!vis[aa.front()]) {
            ans += aa.front();
            cnt++;
        }
        aa.pop_front();
    }
    while(cnt < n + m - 1 && !bb.empty()) {
        if(!vis[bb.front()]) {
            ans += bb.front();
            cnt++;
        }
        bb.pop_front();
    }
    cout << ans << nl;
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

